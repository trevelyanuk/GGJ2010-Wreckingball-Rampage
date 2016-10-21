// week1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <gl\glu.h>
#include <glut.h>
#include <glaux.h>
#include "Game.h"

#include "main.h"
#define MAX_LOADSTRING 100

UINT g_Texture[14]; //array of texture names


				float to=0;
				float tor=0;

			float halfheight; //set screen to display 10 units high
			float heightwidth; //width depends on screen aspect
	
// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
CGame gGame;	

HDC   g_hDC; // General HDC - (handle to device context)
HGLRC g_hRC; // General OpenGL_DC - Our Rendering Context for OpenGL
HINSTANCE g_hInstance;	
HWND g_hWnd;


// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
bool  bSetupPixelFormat(HDC hDC); //added by RM in week 1
void RenderScene();
void CreateTexture(LPSTR strFileName, int textureID);
void CreateTextureWithAlpha( char * filename, unsigned int textureID ) ;

/////////////////////////////
// STEVE 19:57 Mouse variables
float mouse_xPos;
float mouse_yPos; 
bool l_buttonDown = false;
bool r_buttonDown= false;
int height,width; // Moved from WM_Case thingy

bool quits=true;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_EXAM, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_EXAM);

	//prime message
	PeekMessage(&msg, g_hWnd, NULL, NULL, PM_REMOVE);

//enter main loop

while (quits)
	{
	if (PeekMessage(&msg, g_hWnd, NULL, NULL, PM_REMOVE))
		{
		TranslateMessage(&msg);//translate +dispatch to event queue
		DispatchMessage(&msg);
		}
		else
		//do rendering here
		{
		// clear screen and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (gGame.DoFrame(mouse_xPos,mouse_yPos,l_buttonDown,r_buttonDown, width, height)==0) 
		{
			quits=false;
			PostQuitMessage(WM_QUIT);
		}
		SwapBuffers(g_hDC);// bring backbuffer to foreground
		}
	}



	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_EXAM);
	wcex.hCursor		= LoadCursor(NULL, IDC_CROSS);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCTSTR)IDC_EXAM;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   

   hInst = hInstance; // Store instance handle in our global variable
   g_hInstance = hInstance; // Store instance handle in our global variable
int wi=GetSystemMetrics(SM_CXSCREEN);

   g_hWnd = CreateWindow(szWindowClass, szTitle, WS_POPUP|WS_VISIBLE,
      0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), NULL, NULL, hInstance, NULL);

   if (!g_hWnd)
   {
      return FALSE;
   }

   ShowWindow(g_hWnd, nCmdShow);
   UpdateWindow(g_hWnd);

   

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message) 
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam); 
		wmEvent = HIWORD(wParam); 
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
	
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		wglMakeCurrent(NULL, NULL); //This frees our rendering memory and sets 
									//everything back to normal
		wglDeleteContext(g_hRC);	// Delete our OpenGL Rendering Context	
		g_hRC=NULL; 

		if (g_hDC) 
		{
		ReleaseDC(g_hWnd, g_hDC);
		g_hDC=NULL;
		}

		g_hWnd=NULL;

		PostQuitMessage(0);
		break;
	case WM_CREATE:

		g_hDC= GetDC(hWnd);
		bSetupPixelFormat(g_hDC); // call our pixel format setup function
		g_hRC = wglCreateContext(g_hDC); // create rendering context 
		wglMakeCurrent(g_hDC, g_hRC); //and make it current
		
		
		CreateTexture("background.bmp",		1);// background graphic
		CreateTextureWithAlpha("ball.bmp",	2);// background graphic
		CreateTextureWithAlpha("groundV1.bmp",		3);// background graphic
		CreateTextureWithAlpha("groundV2.bmp",		4);// background graphic
		CreateTextureWithAlpha("groundV2.bmp",		5);// background graphic
	

		CreateTextureWithAlpha("tankSheet.bmp",		6);// Tank sheet
		
		//////////// ADDED BY STEVE FOR TANK SHELL 03:26.
		CreateTextureWithAlpha("cannonBall.bmp",		7);// Bullet
		CreateTextureWithAlpha("explosion_new.bmp",		8);// Explosion sheet
		CreateTextureWithAlpha("0-9_sml.bmp",		9);// background graphic

		CreateTextureWithAlpha("Window.bmp",		10);// background graphic
		//	ShowCursor(false);

		CreateTextureWithAlpha("red_dot.bmp",		11);// background graphic
			//ShowCursor(false);
		CreateTextureWithAlpha("PlainBlueBackground.bmp",		12);// background graphic
		CreateTextureWithAlpha("2bonus.bmp",		13);// background graphic
			CreateTextureWithAlpha("4bonus.bmp",		14);// background graphic
			CreateTextureWithAlpha("8bonus.bmp",		15);// background graphic
			CreateTextureWithAlpha("blank.bmp",		16);// background graphic
			
			CreateTextureWithAlpha("cloud1.bmp",		17);// background graphic
			CreateTextureWithAlpha("cloud2.bmp",		18);// background graphic
			
			CreateTextureWithAlpha("start1.bmp",		19);// background graphic
			CreateTextureWithAlpha("start2.bmp",		20);// background graphic
			CreateTextureWithAlpha("start.bmp",		21);// background graphic
			//CreateTextureWithAlpha("start3.bmp",		20);// background graphic
			//CreateTextureWithAlpha("start4.bmp",		21);// background graphic

		//CreateTexture("explod.bmp", 4);// exploding alien graphic
		break;
	case WM_MOUSEMOVE: 

			 halfheight; //set screen to display 10 units high
			 heightwidth; //width depends on screen aspect
		
			  to=LOWORD(lParam);
				 tor=HIWORD(lParam);


		mouse_xPos = (float)((float)LOWORD(lParam)/(float)width)*(float)640; 
		mouse_yPos = (float)((float)HIWORD(lParam)/(float)height)*(float)480; 
		
		break;
	case WM_LBUTTONDOWN:
		l_buttonDown = true;
		break;

	case WM_LBUTTONUP:
		l_buttonDown = false;

	case WM_RBUTTONDOWN:
		r_buttonDown = true;
		break;

	case WM_RBUTTONUP:
		r_buttonDown = false;

		break;

	case WM_SIZE:
		
		height = HIWORD(lParam);	// retrieve width and height
		width = LOWORD(lParam);
		if (height==0)		// don't want a divide by zero
		{
		height=1;					
		}
		glViewport(0, 0, width, height);	// reset the viewport to new dimensions
		glMatrixMode(GL_PROJECTION);//set projection as //current matrix

		{
			glLoadIdentity (); 
			float aspect=(float)width/(float)height;
//			tw=width;
		//	th=height;
			 halfheight=height/2; //set screen to display 10 units high
			 heightwidth=aspect*halfheight; //width depends on screen aspect
			gluOrtho2D(0, 640, 0, 480);
		}

		glMatrixMode(GL_MODELVIEW);	// set modelview matrix
		glLoadIdentity();		// reset modelview matrix
		return 0;
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
		{
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}
	return FALSE;
}

bool
bSetupPixelFormat(HDC hDC)
{
PIXELFORMATDESCRIPTOR pfd; 
int pixelformat; 
 
pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);// Set the size of the structure
pfd.nVersion = 1;					// Always set this to 1
												// Pass in the appropriate OpenGL flags
pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER; 
pfd.dwLayerMask = PFD_MAIN_PLANE;	
// We want the standard mask (this is ignored anyway)
pfd.iPixelType = PFD_TYPE_RGBA;	// We want RGB and Alpha pixel type
pfd.cColorBits = 16;						
pfd.cDepthBits = 0;// Depthbits is ignored for RGBA, but do it anyway
pfd.cAccumBits = 0;	// No special bitplanes needed
pfd.cStencilBits = 0;	// We desire no stencil bits
 
// get a pixel format that best matches one passed in from the device
    if ( (pixelformat = ChoosePixelFormat(hDC, &pfd)) == FALSE ) 
    { 
        MessageBox(NULL, "ChoosePixelFormat failed", "Error", MB_OK); 
        return FALSE; 
    } 
 
// This sets the pixel format that we extracted from above
    if (SetPixelFormat(hDC, pixelformat, &pfd) == FALSE) 
    { 
        MessageBox(NULL, "SetPixelFormat failed", "Error", MB_OK); 
        return FALSE; 
    } 
 
    return TRUE;
}



void   
CreateTexture(LPSTR strFileName, int textureID)
{
	
glEnable(GL_TEXTURE_2D);// Enable Texture Mapping
AUX_RGBImageRec *pBitmap = NULL;
	
if(!strFileName)// Return from the function if no file name was passed in
return;
	
// We need to load the texture data, so we use a cool API that the glaux.lib offers.
	
pBitmap = auxDIBImageLoad(strFileName);// Load the bitmap and store the data
	
if(pBitmap == NULL)// If we can't load the file, quit!
exit(0);

// Now that we have the texture data, we need to register our texture with OpenGL
// To do this we need to call glGenTextures().  The 1 for the first parameter is
// how many texture we want to register this time (we could do a bunch in a row).
// The second parameter is the array index that will hold the reference to this texture.

// Generate a texture with the associative texture ID stored in the array
glGenTextures(1, &g_Texture[textureID]);

// Now that we have a reference for the texture, we need to bind the texture
// to tell OpenGL this is the reference that we are assigning the bitmap data too.
// The first parameter tells OpenGL we want are using a 2D texture, while the
// second parameter passes in the reference we are going to assign the texture too.
// We will use this function later to tell OpenGL we want to use this texture to texture map.

// Bind the texture to the texture arrays index and init the texture
glBindTexture(GL_TEXTURE_2D, g_Texture[textureID]);

// Now comes the important part, we actually pass in all the data from the bitmap to
// create the texture. Here is what the parameters mean in gluBuild2DMipmaps():
// (We want a 2D texture, 3 channels (RGB), bitmap width, bitmap height, It's an RGB format,
//  the data is stored as unsigned bytes, and the actuall pixel data);

// What is a Mip map?  Mip maps are a bunch of scaled pictures from the original.  This makes
// it look better when we are near and farther away from the texture map.  It chooses the
// best looking scaled size depending on where the camera is according to the texture map.
// Otherwise, if we didn't use mip maps, it would scale the original UP and down which would
// look not so good when we got far away or up close, it would look pixelated.

// Build Mipmaps (builds different versions of the picture for distances - looks better)
gluBuild2DMipmaps(GL_TEXTURE_2D, 3, pBitmap->sizeX, pBitmap->sizeY, GL_RGB, GL_UNSIGNED_BYTE, pBitmap->data);

// Lastly, we need to tell OpenGL the quality of our texture map.  GL_LINEAR_MIPMAP_LINEAR
// is the smoothest.  GL_LINEAR_MIPMAP_NEAREST is faster than GL_LINEAR_MIPMAP_LINEAR, 
// but looks blochy and pixilated.  Good for slower computers though.  Read more about 
// the MIN and MAG filters at the bottom of main.cpp
		
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR_MIPMAP_LINEAR);

// Now we need to free the bitmap data that we loaded since openGL stored it as a texture

if (pBitmap)	// If we loaded the bitmap
{
if (pBitmap->data)	// If there is texture data
{
free(pBitmap->data);	// Free the texture data, we don't need it anymore
}
free(pBitmap);	// Free the bitmap structure
	}
}

void CreateTextureWithAlpha( char * filename, unsigned int textureID )    
{
    AUX_RGBImageRec *pImage_RGB = auxDIBImageLoad( filename );
    unsigned char *pImage_RGBA = NULL;

    if( pImage_RGB != NULL )
    {
        int imageSize_RGB  = pImage_RGB->sizeX * pImage_RGB->sizeY * 3;
        int imageSize_RGBA = pImage_RGB->sizeX * pImage_RGB->sizeY * 4;

        // allocate buffer for a RGBA image
        pImage_RGBA = new unsigned char[imageSize_RGBA];

        //
        // Loop through the original RGB image buffer and copy it over to the 
        // new RGBA image buffer setting each pixel that matches the key color
        // transparent.
        //
		
        int i, j;

        for( i = 0, j = 0; i < imageSize_RGB; i += 3, j += 4 )
        {
            // Does the current pixel match the selected color key?
         /*   if( pImage_RGB->data[i]   > 220 &&
                pImage_RGB->data[i+1] < 20 &&
                pImage_RGB->data[i+2] > 220 )*/

			if(( pImage_RGB->data[i] ==  pImage_RGB->data[i+2])&&( pImage_RGB->data[i]>50)&&( pImage_RGB->data[i+1]==0))
            {
                pImage_RGBA[j+3] = 0;   // If so, set alpha to fully transparent.
            }
            else
            {
                pImage_RGBA[j+3] = 255; // If not, set alpha to fully opaque.
            }

            pImage_RGBA[j]   = pImage_RGB->data[i];
            pImage_RGBA[j+1] = pImage_RGB->data[i+1];
            pImage_RGBA[j+2] = pImage_RGB->data[i+2];
        }

        glGenTextures( 1, &textureID );
        glBindTexture( GL_TEXTURE_2D, textureID );
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        // Don't forget to use GL_RGBA for our new image data... we support Alpha transparency now!
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, pImage_RGB->sizeX, pImage_RGB->sizeY, 0,
                      GL_RGBA, GL_UNSIGNED_BYTE, pImage_RGBA );
    }

    if( pImage_RGB )
    {
        if( pImage_RGB->data )
            free( pImage_RGB->data );

        free( pImage_RGB );
    }

    if( pImage_RGBA )
        delete [] pImage_RGBA;
}
