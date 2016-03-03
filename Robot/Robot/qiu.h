/*
This file was produced by Deep Exploration Plugin: CPP Export filter. 

Copyright (C) 1999-2008 Right Hemisphere
Mail support@righthemisphere.com for support.
Visit http://www.righthemisphere.com/dexp.htm for updates.
*/
#include <windows.h>
#include <GL\gl.h>
#include <GL\glu.h>


struct sample_MATERIAL
{
	GLfloat ambient[3];
	GLfloat diffuse[3];
	GLfloat specular[3];
	GLfloat emission[3];
	GLfloat alpha;
	GLfloat phExp;
	int texture;
};

static sample_MATERIAL materials [1] = {
 {{0.117647f,0.117647f,0.117647f},	{0.7f,0.7f,0.7f},	{0.752941f,0.752941f,0.752941f},	{0.0f,0.0f,0.0f},	1.0f,8.0f,-1} //Material #1
};

// 8 Verticies
// 0 Texture Coordinates
// 13 Normals
// 12 Triangles

static BYTE face_indicies[12][9] = {
// TRM_SRF
	{0,1,2 ,0,0,0 ,0,0,0}, {2,3,0 ,0,0,0 ,0,0,0}
// TRM_SRF
	, {5,0,1 ,1,2,3 ,0,0,0}, {1,4,5 ,3,1,1 ,0,0,0}
// TRM_SRF
	, {6,3,5 ,4,5,4 ,0,0,0}, {0,5,3 ,6,4,5 ,0,0,0}
// TRM_SRF
	, {7,2,6 ,7,8,7 ,0,0,0}, {3,6,2 ,9,7,8 ,0,0,0}
// TRM_SRF
	, {4,1,2 ,10,11,11 ,0,0,0}, {2,7,4 ,11,10,10 ,0,0,0}
// TRM_SRF
	, {5,4,7 ,0,12,12 ,0,0,0}, {7,6,5 ,12,0,0 ,0,0,0}
};
static GLfloat vertices [8][3] = {
{-0.5f,0.5f,-0.5f},{-0.5f,-0.5f,-0.5f},{0.5f,-0.5f,-0.5f},
{0.5f,0.5f,-0.5f},{-0.5f,-0.5f,0.5f},{-0.5f,0.5f,0.5f},
{0.5f,0.5f,0.5f},{0.5f,-0.5f,0.5f}
};
static GLfloat normals [13][3] = {
{0.0f,0.0f,1.0f},{-1.0f,0.0f,0.0f},{-1.0f,3.22184e-017f,1.4013e-045f},
{-1.0f,3.22184e-017f,8.94242e-034f},{0.0f,1.0f,0.0f},{4.8721e-018f,1.0f,-1.35228e-034f},
{4.8721e-018f,1.0f,0.0f},{1.0f,0.0f,0.0f},{1.0f,1.00967e-017f,2.80241e-034f},
{1.0f,1.00967e-017f,0.0f},{0.0f,-1.0f,0.0f},{1.0506e-017f,-1.0f,0.0f},
{-6.21348e-018f,0.0f,1.0f}
};
GLfloat textures[1][2]={{0.0f,0.0f}};
/*Material indicies*/
/*{material index,face count}*/
static int material_ref [1][2] = {
{0,12}
};
void MyMaterial(GLenum mode, GLfloat * f, GLfloat alpha)
{
	GLfloat d[4];
	d[0] = f[0];
	d[1] = f[1];
	d[2] = f[2];
	d[3] = alpha;
	glMaterialfv(GL_FRONT_AND_BACK, mode, d);
}

/*
 *  SelectMaterial uses OpenGL commands to define facet colors.
 *
 *  Returns:
 *    Nothing
 */

void SelectMaterial(int i)
{
//
// Define the reflective properties of the 3D Object faces.
//
	glEnd();
	GLfloat alpha = materials[i].alpha;
	MyMaterial(GL_AMBIENT, materials[i].ambient, alpha);
	MyMaterial(GL_DIFFUSE, materials[i].diffuse, alpha);
	MyMaterial(GL_SPECULAR, materials[i].specular, alpha);
	MyMaterial(GL_EMISSION, materials[i].emission, alpha);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materials[i].phExp);
	glBegin(GL_TRIANGLES);

};

GLint Gen3DObjectList()
{
	int i;
	int j;

 GLint lid=glGenLists(1);
	int mcount=0;
	int mindex=0;
   glNewList(lid, GL_COMPILE);

    glBegin (GL_TRIANGLES);
      for(i=0;i<sizeof(face_indicies)/sizeof(face_indicies[0]);i++)
       {
	if (!mcount)
	{
		SelectMaterial(material_ref[mindex][0]);
		mcount = material_ref[mindex][1];
		mindex ++;
	}
	mcount --;
       for(j=0;j<3;j++)
        {
          int vi=face_indicies[i][j];
          int ni=face_indicies[i][j+3];//Normal index
          int ti=face_indicies[i][j+6];//Texture index
           glNormal3f (normals[ni][0],normals[ni][1],normals[ni][2]);
           glTexCoord2f(textures[ti][0],textures[ti][1]);
           glVertex3f (vertices[vi][0],vertices[vi][1],vertices[vi][2]);
        }
       }
    glEnd ();

   glEndList();
   return lid;
};
