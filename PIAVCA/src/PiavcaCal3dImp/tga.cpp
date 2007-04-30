//----------------------------------------------------------------------------//
// viewer.h                                                                   //
// Copyright (C) 2003 Desmecht Laurent                                        //
//----------------------------------------------------------------------------//
// This program is free software; you can redistribute it and/or modify it    //
// under the terms of the GNU General Public License as published by the Free //
// Software Foundation; either version 2 of the License, or (at your option)  //
// any later version.                                                         //
//----------------------------------------------------------------------------//

#include "tga.h"
#include <iostream>

#define TGA_TYPE_MAPPED 1
#define TGA_TYPE_COLOR 2
#define TGA_TYPE_GRAY 3
#define TGA_TYPE_MAPPED_RLE 9
#define TGA_TYPE_COLOR_RLE 10
#define TGA_TYPE_GRAY_RLE 11

/* Image descriptor.
      3-0: attribute bpp
      4:   left-to-right ordering
      5:   top-to-bottom ordering
      7-6: zero
*/
#define TGA_DESC_ABITS 0x0f
#define TGA_DESC_HORIZONTAL 0x10
#define TGA_DESC_VERTICAL 0x20




CTga::CTga()
{
	m_SizeX=0;
	m_SizeY=0;
	m_Bpp=0;
	m_dest=NULL;
}

int CTga::Release()
{
	if(m_dest!=NULL)
	{
		free(m_dest);
		m_dest=NULL;
		return -1;
	}
	return 0;
}

int CTga::ReadFile(const char *str)
{
	unsigned char l,r,g,b,a;
    unsigned char *tmp;
    
    if(m_dest!=NULL)
    {
    	return -1;    	
    }


	FILE *file;
//#ifdef WIN32
//	fopen_s(&file, str, "rb"); 
//#else
	file=fopen(str,"rb");
//#endif
	
    if(file==NULL)
	{
		std::cout << "TGA Texture Load Error: could not open file " << str << std::endl;
        return 0;
	};
        
    // Read the header
    
	TgaHeader.idlength=fgetc(file);	
	TgaHeader.colourmaptype=fgetc(file);
	TgaHeader.datatypecode=fgetc(file);
	TgaHeader.colourmaporigin=fgetc(file);
	TgaHeader.colourmaporigin+=fgetc(file)<<8;
	TgaHeader.colourmaplength=fgetc(file);
	TgaHeader.colourmaplength+=fgetc(file)<<8; 
	TgaHeader.colourmapdepth=fgetc(file);
	TgaHeader.x_origin=fgetc(file); 
	TgaHeader.x_origin+=fgetc(file)<<8; 
	TgaHeader.y_origin=fgetc(file);
	TgaHeader.y_origin+=fgetc(file)<<8;
	TgaHeader.SizeX=fgetc(file);
	TgaHeader.SizeX+=fgetc(file)<<8;
	TgaHeader.SizeY=fgetc(file);
	TgaHeader.SizeY+=fgetc(file)<<8;
	TgaHeader.Bpp=fgetc(file);
	TgaHeader.imagedescriptor=fgetc(file);

	// Return if the format is unsupported		
	
    if(TgaHeader.datatypecode!=TGA_TYPE_COLOR
            && TgaHeader.datatypecode!=TGA_TYPE_GRAY
            && TgaHeader.datatypecode!=TGA_TYPE_COLOR_RLE)
	{
		std::cout << "TGA Texture Load Error: unsupported TGA type, only color, gray and RLE supported (mapped types not supported)" << std::endl;
        return 0;
	};
	
    if(TgaHeader.Bpp!=8
            && TgaHeader.Bpp!=24
            && TgaHeader.Bpp!=32)
	{
		std::cout << "TGA Texture Load Error: unsupported TGA Bits per pixel, only 8, 24 and 32-bit images supported" << std::endl;
        return 0;
	};

	
    if(TgaHeader.Bpp==8)
        m_dest = (unsigned char*)malloc(TgaHeader.SizeX*TgaHeader.SizeY);
    if(TgaHeader.Bpp==32 || TgaHeader.Bpp==24)
        m_dest = (unsigned char*)malloc(TgaHeader.SizeX*TgaHeader.SizeY*4);



    if(TgaHeader.datatypecode==TGA_TYPE_COLOR || TgaHeader.datatypecode==TGA_TYPE_GRAY)
    {
        for(int y=0;y<TgaHeader.SizeY;y++)
            for(int x=0;x<TgaHeader.SizeX;x++)
            {
				
                if(TgaHeader.Bpp==8)
                {
                    r=fgetc(file);
                    m_dest[x+y*TgaHeader.SizeX]=r;
                }
                if(TgaHeader.Bpp==24 || TgaHeader.Bpp==32)
                {
                    b=fgetc(file);
                    g=fgetc(file);
                    r=fgetc(file);
					if(TgaHeader.Bpp==24)
                        a=255;
                    else
                        a=fgetc(file);
					
                    m_dest[(x+y*TgaHeader.SizeX)*4]=r;
                    m_dest[(x+y*TgaHeader.SizeX)*4+1]=g;
                    m_dest[(x+y*TgaHeader.SizeX)*4+2]=b;
                    m_dest[(x+y*TgaHeader.SizeX)*4+3]=a;
                }
            }
    }
    if(TgaHeader.datatypecode==TGA_TYPE_COLOR_RLE)
    {
        int x=0;
        while(x<TgaHeader.SizeX*TgaHeader.SizeY)
        {
            l=fgetc(file);
            if(l & 0x80)
            {
                l=l & 0x7F;
                b=fgetc(file);
                g=fgetc(file);
                r=fgetc(file);
                if(TgaHeader.Bpp==24)
                   a=255;
	            else
                   a=fgetc(file);


                for(int i=0;i<l+1;i++)
                {
                    m_dest[x*4]=r;
                    m_dest[x*4+1]=g;
                    m_dest[x*4+2]=b;
                    m_dest[x*4+3]=a;
                    x++;
                }
            }
            else
            {
                l=l & 0x7F;
                for(int i=0;i<l+1;i++)
                {
                    b=fgetc(file);
                    g=fgetc(file);
                    r=fgetc(file);
                    
                    if(TgaHeader.Bpp==24)
                        a=255;
                    else
                        a=fgetc(file);


                    m_dest[x*4]=r;
                    m_dest[x*4+1]=g;
                    m_dest[x*4+2]=b;
                    m_dest[x*4+3]=a;
                    x++;
                }
            }
        }
    }


    m_Bpp=TgaHeader.Bpp;
    if(m_Bpp==24)m_Bpp=32;
    fclose(file);

	// resample so that the sizes of the edges are powers of 2

	int image_x = TgaHeader.SizeX;
	int image_y = TgaHeader.SizeY;
	int i;
	for (i = 1; i < TgaHeader.SizeX; i*=2)
		/*do nothing*/;
	TgaHeader.SizeX = i;
	float x_scale = ((float) (image_x-1))/((float) (TgaHeader.SizeX-1));
	for (i = 1; i < image_x; i*=2)
		/*do nothing*/;
	TgaHeader.SizeY = i;
	float y_scale = ((float) (image_y-1))/((float) (TgaHeader.SizeY-1));
   
    m_SizeX=TgaHeader.SizeX;
    m_SizeY=TgaHeader.SizeY;

    tmp=m_dest;

    if(TgaHeader.Bpp==8)
        m_dest = (unsigned char*)malloc(TgaHeader.SizeX*TgaHeader.SizeY);
    if(TgaHeader.Bpp==32 || TgaHeader.Bpp==24)
        m_dest = (unsigned char*)malloc(TgaHeader.SizeX*TgaHeader.SizeY*4);


	int prev_x = 0, prev_y = 0;
	int next_x = 1, next_y = 1;
	unsigned char r_interp[2][2],g_interp[2][2],b_interp[2][2],a_interp[2][2];
    for(int y=0;y<TgaHeader.SizeY;y++)
    {
		next_x=1;
		prev_x=0;
		float mapped_y = y*y_scale;
		if(mapped_y > next_y)
		{
			next_y++;
			prev_y++;
		}
		float y_remainder = mapped_y - prev_y;
        for(int x=0;x<TgaHeader.SizeX;x++)
        {
			float mapped_x = x*x_scale;
			if(mapped_x > next_x)
			{
				next_x++;
				prev_x++;
			}
			float x_remainder = mapped_x - prev_x;
			if(m_Bpp==8)
            {
                if((TgaHeader.imagedescriptor & 0x0020)==0)  //we flip the file
				{
					r_interp[0][0]=tmp[prev_x+(image_y-prev_y-1)*image_x];
					r_interp[0][1]=tmp[next_x+(image_y-prev_y-1)*image_x];
					r_interp[1][0]=tmp[prev_x+(image_y-next_y-1)*image_x];
					r_interp[1][1]=tmp[next_x+(image_y-next_y-1)*image_x];
				}
				else
				{
					r_interp[0][0]=tmp[prev_x+prev_y*image_x];
					r_interp[0][1]=tmp[next_x+prev_y*image_x];
					r_interp[1][0]=tmp[prev_x+next_y*image_x];
					r_interp[1][1]=tmp[next_x+next_y*image_x];
				}
				r_interp[0][0] = (unsigned char) ((r_interp[0][1] - r_interp[0][0])*x_remainder + r_interp[0][0]);
				r_interp[1][0] = (unsigned char) ((r_interp[1][1] - r_interp[1][0])*x_remainder + r_interp[1][0]);
				r = (unsigned char)  ((r_interp[1][0] - r_interp[0][0])*y_remainder + r_interp[0][0]);
                m_dest[x+y*TgaHeader.SizeX]=r;
            }
            if(m_Bpp==32)
            {
                if((TgaHeader.imagedescriptor & 0x0020)==0)  //we flip the file
				{
					r_interp[0][0]=tmp[(prev_x+(image_y-prev_y-1)*image_x)*4];
					r_interp[0][1]=tmp[(next_x+(image_y-prev_y-1)*image_x)*4];
					r_interp[1][0]=tmp[(prev_x+(image_y-next_y-1)*image_x)*4];
					r_interp[1][1]=tmp[(next_x+(image_y-next_y-1)*image_x)*4];
					
					g_interp[0][0]=tmp[(prev_x+(image_y-prev_y-1)*image_x)*4+1];
					g_interp[0][1]=tmp[(next_x+(image_y-prev_y-1)*image_x)*4+1];
					g_interp[1][0]=tmp[(prev_x+(image_y-next_y-1)*image_x)*4+1];
					g_interp[1][1]=tmp[(next_x+(image_y-next_y-1)*image_x)*4+1];
					
					b_interp[0][0]=tmp[(prev_x+(image_y-prev_y-1)*image_x)*4+2];
					b_interp[0][1]=tmp[(next_x+(image_y-prev_y-1)*image_x)*4+2];
					b_interp[1][0]=tmp[(prev_x+(image_y-next_y-1)*image_x)*4+2];
					b_interp[1][1]=tmp[(next_x+(image_y-next_y-1)*image_x)*4+2];
					
					a_interp[0][0]=tmp[(prev_x+(image_y-prev_y-1)*image_x)*4+3];
					a_interp[0][1]=tmp[(next_x+(image_y-prev_y-1)*image_x)*4+3];
					a_interp[1][0]=tmp[(prev_x+(image_y-next_y-1)*image_x)*4+3];
					a_interp[1][1]=tmp[(next_x+(image_y-next_y-1)*image_x)*4+3];
					
					//r=tmp[(x+(TgaHeader.SizeY-y-1)*TgaHeader.SizeX)*4];
					//g=tmp[(x+(TgaHeader.SizeY-y-1)*TgaHeader.SizeX)*4+1];
					//b=tmp[(x+(TgaHeader.SizeY-y-1)*TgaHeader.SizeX)*4+2];
					//a=tmp[(x+(TgaHeader.SizeY-y-1)*TgaHeader.SizeX)*4+3];
				}
				else
				{
					r_interp[0][0]=tmp[(prev_x+prev_y*image_x)*4];
					r_interp[0][1]=tmp[(next_x+prev_y*image_x)*4];
					r_interp[1][0]=tmp[(prev_x+next_y*image_x)*4];
					r_interp[1][1]=tmp[(next_x+next_y*image_x)*4];
					
					g_interp[0][0]=tmp[(prev_x+prev_y*image_x)*4+1];
					g_interp[0][1]=tmp[(next_x+prev_y*image_x)*4+1];
					g_interp[1][0]=tmp[(prev_x+next_y*image_x)*4+1];
					g_interp[1][1]=tmp[(next_x+next_y*image_x)*4+1];
					
					b_interp[0][0]=tmp[(prev_x+prev_y*image_x)*4+2];
					b_interp[0][1]=tmp[(next_x+prev_y*image_x)*4+2];
					b_interp[1][0]=tmp[(prev_x+next_y*image_x)*4+2];
					b_interp[1][1]=tmp[(next_x+next_y*image_x)*4+2];
					
					a_interp[0][0]=tmp[(prev_x+prev_y*image_x)*4+3];
					a_interp[0][1]=tmp[(next_x+prev_y*image_x)*4+3];
					a_interp[1][0]=tmp[(prev_x+next_y*image_x)*4+3];
					a_interp[1][1]=tmp[(next_x+next_y*image_x)*4+3];
				}
                r_interp[0][0] = (unsigned char) ((r_interp[0][1] - r_interp[0][0])*x_remainder + r_interp[0][0]);
				r_interp[1][0] = (unsigned char) ((r_interp[1][1] - r_interp[1][0])*x_remainder + r_interp[1][0]);
				r = (unsigned char) ((r_interp[1][0] - r_interp[0][0])*y_remainder + r_interp[0][0]);
                //r = r_interp[1][1];
				m_dest[(x+y*TgaHeader.SizeX)*4]=r;
                
				g_interp[0][0] = (unsigned char) ((g_interp[0][1] - g_interp[0][0])*x_remainder + g_interp[0][0]);
				g_interp[1][0] = (unsigned char) ((g_interp[1][1] - g_interp[1][0])*x_remainder + g_interp[1][0]);
				g = (unsigned char) ((g_interp[1][0] - g_interp[0][0])*y_remainder + g_interp[0][0]);
                //g = g_interp[1][1];
				m_dest[(x+y*TgaHeader.SizeX)*4+1]=g;
                
				b_interp[0][0] = (unsigned char) ((b_interp[0][1] - b_interp[0][0])*x_remainder + b_interp[0][0]);
				b_interp[1][0] = (unsigned char) ((b_interp[1][1] - b_interp[1][0])*x_remainder + b_interp[1][0]);
				b = (unsigned char) ((b_interp[1][0] - b_interp[0][0])*y_remainder + b_interp[0][0]);
                //b = b_interp[1][1];
				m_dest[(x+y*TgaHeader.SizeX)*4+2]=b;

				a_interp[0][0] = (unsigned char) ((a_interp[0][1] - a_interp[0][0])*x_remainder + a_interp[0][0]);
				a_interp[1][0] = (unsigned char) ((a_interp[1][1] - a_interp[1][0])*x_remainder + a_interp[1][0]);
				a = (unsigned char) ((a_interp[1][0] - a_interp[0][0])*y_remainder + a_interp[0][0]);
                //a = a_interp[1][1];
				m_dest[(x+y*TgaHeader.SizeX)*4+3]=a;
            }
        }

    }
	/*for(int y=0;y<TgaHeader.SizeY;y++)
	{
		m_dest[(0+y*TgaHeader.SizeX)*4]  =255;
		m_dest[(0+y*TgaHeader.SizeX)*4+1]=255;
		m_dest[(0+y*TgaHeader.SizeX)*4+2]=255;
		m_dest[(0+y*TgaHeader.SizeX)*4+3]=255;
	}*/
    free(tmp);


	
    //if((TgaHeader.imagedescriptor & 0x0020)==0)  //we flip the file
    //{

    //    tmp=m_dest;

    //    if(TgaHeader.Bpp==8)
    //        m_dest = (unsigned char*)malloc(TgaHeader.SizeX*TgaHeader.SizeY);
    //    if(TgaHeader.Bpp==32 || TgaHeader.Bpp==24)
    //        m_dest = (unsigned char*)malloc(TgaHeader.SizeX*TgaHeader.SizeY*4);


    //    for(int y=0;y<TgaHeader.SizeY;y++)
    //    {
    //        for(int x=0;x<TgaHeader.SizeX;x++)
    //        {
    //            if(m_Bpp==8)
    //            {
    //                r=tmp[x+(TgaHeader.SizeY-y-1)*TgaHeader.SizeX];
    //                m_dest[x+y*TgaHeader.SizeX]=r;
    //            }
    //            if(m_Bpp==32)
    //            {
    //                r=tmp[(x+(TgaHeader.SizeY-y-1)*TgaHeader.SizeX)*4];
    //                g=tmp[(x+(TgaHeader.SizeY-y-1)*TgaHeader.SizeX)*4+1];
    //                b=tmp[(x+(TgaHeader.SizeY-y-1)*TgaHeader.SizeX)*4+2];
    //                a=tmp[(x+(TgaHeader.SizeY-y-1)*TgaHeader.SizeX)*4+3];
    //                m_dest[(x+y*TgaHeader.SizeX)*4]=r;
    //                m_dest[(x+y*TgaHeader.SizeX)*4+1]=g;
    //                m_dest[(x+y*TgaHeader.SizeX)*4+2]=b;
    //                m_dest[(x+y*TgaHeader.SizeX)*4+3]=a;


    //            }
    //        }

    //    }
    //    free(tmp);
    //}



    return -1;

}



