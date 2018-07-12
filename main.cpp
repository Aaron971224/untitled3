#include "odbchelper.h"
#include <QApplication>
#ifndef INITIAL_OPENGL
#define INITIAL_OPENGL
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)
VTK_MODULE_INIT(vtkRenderingFreeType)
#endif
#include <iostream>
using namespace std;
#include <vtkVersion.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkCamera.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyData.h>
#include <vtkSphereSource.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkAxesActor.h>
#include <vtkPropAssembly.h>
#include <vtkSmartPointer.h>
#include <vtkProperty.h>
#include <vtkInteractorStyleTrackballCamera.h>

void myShow(vtkPolyData* aGrid)
{
    int i;

    vtkSmartPointer<vtkPolyDataMapper> aMapper=vtkSmartPointer<vtkPolyDataMapper>::New();
    aMapper->SetInputData(aGrid);
    aMapper->ScalarVisibilityOn();

    vtkSmartPointer<vtkActor> anActor=vtkSmartPointer<vtkActor>::New();
    anActor->SetMapper(aMapper);
    //    anActor->GetProperty()->SetRepresentationToWireframe();
    anActor->GetProperty()->SetDiffuseColor(1,1,1);
    anActor->GetProperty()->SetLineWidth(10);
    anActor->GetProperty()->SetPointSize(10);

    vtkSmartPointer<vtkRenderer> ren1=vtkSmartPointer<vtkRenderer>::New();
    vtkSmartPointer<vtkRenderWindow> renWin=vtkSmartPointer<vtkRenderWindow>::New();
    ren1->AddActor(anActor);
    ren1->ResetCamera();
    renWin->AddRenderer(ren1);
    renWin->SetSize(512,512);
    int i;
       for (i = 0; i < 360; ++i)
       {
         renWin->Render();
         ren1->GetActiveCamera()->Azimuth( 1 );
       }
    vtkSmartPointer<vtkRenderWindowInteractor> iren=vtkSmartPointer<vtkRenderWindowInteractor>::New();
    iren->SetRenderWindow(renWin);
    vtkSmartPointer<vtkInteractorStyleTrackballCamera> style=vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();
    iren->SetInteractorStyle(style);
/***************坐标互动窗件儿***************************************/
    vtkSmartPointer<vtkAxesActor> axes =vtkSmartPointer<vtkAxesActor>::New();
    vtkSmartPointer<vtkOrientationMarkerWidget> widget =vtkSmartPointer<vtkOrientationMarkerWidget>::New();
    widget->SetOutlineColor( 0.9300, 0.5700, 0.1300 );
    widget->SetOrientationMarker( axes );
    //注意style的设置要在axes设置之前
    widget->SetInteractor( iren );
    widget->SetViewport( 0.0, 0.0, 0.4, 0.4 );
    widget->SetEnabled( 1 );
    widget->InteractiveOn();
/***************坐标互动窗件儿***************************************/
    iren->Start();

}
int main()
{
    vtkSmartPointer<vtkSphereSource> sphereSource = vtkSmartPointer<vtkSphereSource>::New();
    sphereSource->SetCenter(0.0, 0.0, 0.0);
    sphereSource->SetRadius(1.0);
    sphereSource->Update();

    vtkSmartPointer<vtkPolyData> polydata = vtkSmartPointer<vtkPolyData>::New();
    polydata=sphereSource->GetOutput();
    myShow(polydata);
    return 0;
}
