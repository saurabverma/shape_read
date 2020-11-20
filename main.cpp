
#include <shapefil.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cstring>

#include <iostream>
#include <fstream>

using namespace std;
 
 
typedef struct MyPoint2D
{
 double dX;
 double dY;
 
}MyPoint2D;

//Function to Open Shapefile and parse the info 
void OpenShapeFile(char* fileName)
{
	ofstream myfile;
	myfile.open("output.txt");

	SHPHandle hSHP=SHPOpen(fileName, "rb" );

	if(hSHP == NULL) return;

	// NOTE: Only Point is different encoding, others are similar

	//Point Shapefile
    if(hSHP->nShapeType == SHPT_POINT)
    {
		myfile << "\n***** Point *****\n\n";
		SHPObject *psShape;
		for(int i=0;i<hSHP->nRecords;i++)
        {
            psShape = SHPReadObject(hSHP, i);

            double fX = psShape->padfX[0];
            double fY = psShape->padfY[0];

			myfile << "x: " << fX << "\ny: " << fY << "\n\n";			
		}
    }


	//Line Shapefile
    else if(hSHP->nShapeType == SHPT_ARC)
    {
		myfile << "\n***** Polyline *****\n\n";
		SHPObject *psShape;
		for(int i=0;i<hSHP->nRecords;i++)
        {
            psShape = SHPReadObject(hSHP, i);
            vector<MyPoint2D> tempPointArray;

            for(int j=0;j<psShape->nVertices;j++)
            {
				double fX = psShape->padfX[j];
				double fY = psShape->padfY[j];
				MyPoint2D pt;
				pt.dX=fX;
				pt.dY=fY;
				tempPointArray.push_back(pt);
			}

			myfile << i << ":\nx: [";
			for (const auto item: tempPointArray)
				myfile << to_string(item.dX) << ", ";
			myfile << "]\ny: [";
			for (const auto item: tempPointArray)
				myfile << to_string(item.dY) << ", ";
			myfile << "]\n\n";
        }
    }

 	//Polygon Shapefile
    if(hSHP->nShapeType == SHPT_POLYGON)
    {
		myfile << "\n***** Polygon *****\n\n";
		SHPObject *psShape;
		for(int i=0;i<hSHP->nRecords;i++)
		{
			psShape = SHPReadObject(hSHP, i);
      		vector<MyPoint2D> tempPointArray;
     
			for(int j=0;j<psShape->nVertices;j++)
			{
				double fX = psShape->padfX[j];
				double fY = psShape->padfY[j];
				MyPoint2D pt;
				pt.dX=fX;
				pt.dY=fY;
      			tempPointArray.push_back(pt);
			}

			myfile << i << ":\nx: [";
			for (const auto item : tempPointArray)
				myfile << to_string(item.dX) << ", ";
			myfile << "]\ny: [";
			for (const auto item : tempPointArray)
				myfile << to_string(item.dY) << ", ";
			myfile << "]\n\n";
		}
	}

	//PolylineZ Shapefile
	if (hSHP->nShapeType == SHPT_ARCZ)
	{
		myfile << "\n***** PolylineZ *****\n\n";
		SHPObject *psShape;
		for (int i = 0; i < hSHP->nRecords; i++)
		{
			psShape = SHPReadObject(hSHP, i);
			vector<MyPoint2D> tempPointArray;

			for (int j = 0; j < psShape->nVertices; j++)
			{
				double fX = psShape->padfX[j];
				double fY = psShape->padfY[j];
				MyPoint2D pt;
				pt.dX = fX;
				pt.dY = fY;
				tempPointArray.push_back(pt);
			}

			myfile << i << ":\nx: [";
			for (const auto item : tempPointArray)
				myfile << to_string(item.dX) << ", ";
			myfile << "]\ny: [";
			for (const auto item : tempPointArray)
				myfile << to_string(item.dY) << ", ";
			myfile << "]\n\n";
		}
	}

	myfile.close();
}

int main(int argc, char** argv)
{
	// NOTE: Mention either shp or shx filename, but the other file must be
	// present in same directory

	string s = "test.shp";
	int n = s.length();
	char char_array[n + 1];
	strcpy(char_array, s.c_str());
	OpenShapeFile(char_array); //Line Shapefile
    return 0;
}
