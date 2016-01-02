#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Printer.H>
#include <FL/Fl_Sys_Menu_Bar.H>
#include <FL/Enumerations.H>
#include <FL/Fl_Tile.H>
#include <FL/Fl_Tabs.H>

#include "SearchCriteriaGroup.h"
#include "ToolBarGroup.h"
#include "ResultGroup.h"
#include "Controller.h"

using namespace std;

const Fl_Color MYBACKCOLOR = fl_lighter( FL_GRAY);

void beendenCallback( Fl_Widget*, void* ) {
    if( Fl::event() == 10 ) {
        //Fl::event() == 10: x in der Titelleiste gedrückt oder
        //"Schließen" im Systemmenü. Nur damit soll
        //Anwendung geschlossen werden können.
        //Fl::event() == 12: ESC gedrückt; Anwendung *nicht* schließen
        exit( 0 );
    }
}

int main( ) {
    int X = 100, Y = 50, W = SearchCriteriaGroup::getPreferredWidth(), 
            H = 800, H_TOOLBAR = 40, H_STATUSBAR = 24;
    
    Fl_Double_Window *win = new Fl_Double_Window( X, Y, W, H, "NumisHistory" );
    win->callback( beendenCallback );
    
    ////////// ToolBar
    ToolBarGroup *pToolBar = new ToolBarGroup( 0, 0, W, MYBACKCOLOR );
    
    ////////// Recherche-Kriterien 
    SearchCriteriaGroup *pSearch = new SearchCriteriaGroup( 0+1, pToolBar->h(), W-2 );
    
    ////////// Ergebnis der Suche
    int yrg = pSearch->y() + pSearch->h();
    int hrg = H - yrg - H_STATUSBAR;
    ResultGroup *pResult = new ResultGroup( pSearch->x(), yrg, pSearch->w(), hrg );
    pResult->color( MYBACKCOLOR );
    
    ///////// StatusBar
    Fl_Group *pStatusBar = new Fl_Group( 0, win->h()-H_STATUSBAR, W, H_STATUSBAR );
    pStatusBar->box( FL_FLAT_BOX );
    pStatusBar->color( MYBACKCOLOR );
    pStatusBar->label( "Bereit." );
    pStatusBar->align( FL_ALIGN_LEFT | FL_ALIGN_INSIDE );
    pStatusBar->end();
    
    win->end( );
    win->resizable( pResult );
    
      
    /////////// Controller
    Controller *pCtrl = new Controller( *pToolBar, *pSearch, *pResult );
    pCtrl->init();

    win->show( );

    return Fl::run( );
}