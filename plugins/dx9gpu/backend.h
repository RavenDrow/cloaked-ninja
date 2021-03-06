#pragma once

////////////////////////////////////////////////////////////////////////
// Init
////////////////////////////////////////////////////////////////////////
void BK_Init();

////////////////////////////////////////////////////////////////////////
// Texture
////////////////////////////////////////////////////////////////////////
enum bk_sampler {
	SAMPLER_LINEAR,
	SAMPLER_POINT
};

enum bk_wrap {
	WRAP_CLAMP,
	WRAP_REPEAT
};

// Backend dependend
struct BK_Texture;

typedef struct {
	BK_Texture * _private;
	// sampler
	bk_sampler sampler;
	bk_wrap wrap;
} bk_texture_t;

void BK_InitTextures();
bk_texture_t * BK_CreateTexture(int width, int height, int use_atlas = 1);
void BK_SetTexture(bk_texture_t * texture);
void BK_DeleteTexture(bk_texture_t * texture);
int BK_SetTextureData(bk_texture_t * texture, int texw, int texh, void * data);
int BK_SetSubTextureData(bk_texture_t * texture, int xoffset, int yoffset, int texw, int texh, void * data);
unsigned int BK_GetGlTexture(bk_texture_t * texture);

void * BK_TextureLock(bk_texture_t * texture, int * pitch);
void BK_TextureUnlock(bk_texture_t * texture);
void BK_TextureEnable();
void BK_TextureDisable();

bk_texture_t * BK_GetFrameBuffer();

// Lock / Unlock (should use it)
void BK_LockTexture(bk_texture_t * texture, void ** data, int * pitch);
void BK_UnlockTexture(bk_texture_t * texture);

////////////////////////////////////////////////////////////////////////
// OpenGL primitive drawing commands
////////////////////////////////////////////////////////////////////////
void PRIMdrawTexturedQuad(OGLVertex* vertex1, OGLVertex* vertex2, 
                                   OGLVertex* vertex3, OGLVertex* vertex4);

///////////////////////////////////////////////////////// 
void PRIMdrawTexturedTri(OGLVertex* vertex1, OGLVertex* vertex2, 
                                  OGLVertex* vertex3);

///////////////////////////////////////////////////////// 
void PRIMdrawTexGouraudTriColor(OGLVertex* vertex1, OGLVertex* vertex2, 
                                         OGLVertex* vertex3);

///////////////////////////////////////////////////////// 
void PRIMdrawTexGouraudTriColorQuad(OGLVertex* vertex1, OGLVertex* vertex2, 
                                             OGLVertex* vertex3, OGLVertex* vertex4);

///////////////////////////////////////////////////////// 
void PRIMdrawTri(OGLVertex* vertex1, OGLVertex* vertex2, OGLVertex* vertex3);

///////////////////////////////////////////////////////// 
void PRIMdrawTri2(OGLVertex* vertex1, OGLVertex* vertex2, 
                           OGLVertex* vertex3, OGLVertex* vertex4);

///////////////////////////////////////////////////////// 
void PRIMdrawGouraudTriColor(OGLVertex* vertex1, OGLVertex* vertex2, 
                                      OGLVertex* vertex3);
///////////////////////////////////////////////////////// 
void PRIMdrawGouraudTri2Color(OGLVertex* vertex1, OGLVertex* vertex2, 
                                       OGLVertex* vertex3, OGLVertex* vertex4);

///////////////////////////////////////////////////////// 
void PRIMdrawFlatLine(OGLVertex* vertex1, OGLVertex* vertex2,OGLVertex* vertex3, OGLVertex* vertex4);

///////////////////////////////////////////////////////// 
void PRIMdrawGouraudLine(OGLVertex* vertex1, OGLVertex* vertex2,OGLVertex* vertex3, OGLVertex* vertex4);

///////////////////////////////////////////////////////// 
void PRIMdrawQuad(OGLVertex* vertex1, OGLVertex* vertex2, 
                           OGLVertex* vertex3, OGLVertex* vertex4) ;


////////////////////////////////////////////////////////////////////////
// paint it black: simple func to clean up optical border garbage
////////////////////////////////////////////////////////////////////////
void PaintBlackBorders(void);

////////////////////////////////////////////////////////////////////////
// Aspect ratio of ogl screen: simply adjusting ogl view port
////////////////////////////////////////////////////////////////////////
void SetAspectRatio(void);

////////////////////////////////////////////////////////////////////////
// vram read check (reading from card's back/frontbuffer if needed... 
// slow!)
////////////////////////////////////////////////////////////////////////
void CheckVRamRead(int x, int y, int dx, int dy,BOOL bFront);

////////////////////////////////////////////////////////////////////////
// vram read check ex (reading from card's back/frontbuffer if needed...
// slow!)
////////////////////////////////////////////////////////////////////////
void CheckVRamReadEx(int x, int y, int dx, int dy);

////////////////////////////////////////////////////////////////////////
// resize renderer view
////////////////////////////////////////////////////////////////////////
void BK_SetView(int w, int h);

////////////////////////////////////////////////////////////////////////
// Display
////////////////////////////////////////////////////////////////////////
void BK_SwapBuffer();

////////////////////////////////////////////////////////////////////////
// Clear
////////////////////////////////////////////////////////////////////////
void BK_Clear(uint32_t flags, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void BK_ClearDepth();

////////////////////////////////////////////////////////////////////////
// Opaque
////////////////////////////////////////////////////////////////////////
void BK_OpaqueOn();
void BK_OpaqueOff();

////////////////////////////////////////////////////////////////////////
// Scissor
//////////////////////////////////////////////////////////////////////// 
void BK_ScissorEnable();
void BK_ScissorDisable();
void BK_Scissor(int x, int y, int w, int h);

////////////////////////////////////////////////////////////////////////
// Alpha
//////////////////////////////////////////////////////////////////////// 
void BK_AlphaEnable();
void BK_AlphaDisable();

////////////////////////////////////////////////////////////////////////
// Blend
//////////////////////////////////////////////////////////////////////// 
void BK_BlendEnable();
void BK_BlendDisable();
void BK_BlendFunc(int func);

////////////////////////////////////////////////////////////////////////
// Depth
//////////////////////////////////////////////////////////////////////// 
void BK_DepthEnable();
void BK_DepthDisable();
void BK_DepthMask();
void BK_DepthUnmask();

void BK_UpdateShaders();

////////////////////////////////////////////////////////////////////////
// Color
//////////////////////////////////////////////////////////////////////// 
void BK_SetColor(unsigned char * c);

//////////////////////////////////////////////////////////////////////// 
void SetSemiTrans(void);


extern bk_texture_t * gTexName;
extern bk_texture_t * gTexFrameName;