#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Printer.H>
#include <FL/Fl_Sys_Menu_Bar.H>
#include <FL/Enumerations.H>
#include <FL/Fl_Tile.H>
#include <FL/Fl_Tabs.H>
#include <vector>
#include <algorithm>

using namespace std;

const Fl_Color MYBACKCOLOR = fl_lighter( FL_GRAY);

///////////// Menu Items Callbacks ///////////////

void neueQueryCallback( Fl_Widget*, void* ) {
    fprintf( stderr, "neue Query \n" ) ;
}
void neueRechercheCallback( Fl_Widget*, void* ) {
    fprintf( stderr, "neue Recherche \n" ) ;
}
void openQueryCallback( Fl_Widget*, void* ) {
    fprintf( stderr, "öffnen Query \n" ) ;
}
void mruCallback( Fl_Widget*, void* ) {
    fprintf( stderr, "MRU-Liste \n" ) ;
}
void speichernQueryCallback( Fl_Widget*, void* ) {
    fprintf( stderr, "speichern Query \n" ) ;
}
void speichernQueryAlsCallback( Fl_Widget*, void* ) {
    fprintf( stderr, "speichern Query als \n" ) ;
}
void runQueryCallback( Fl_Widget*, void* ) {
    fprintf( stderr, "ausführen Query \n" ) ;
}
void excelExportCallback( Fl_Widget*, void* ) {
    fprintf( stderr, "excel export \n" ) ;
}
void beendenCallback( Fl_Widget*, void* ) {
    fprintf( stderr, "beenden Callback\n" ) ;
    if( Fl::event_key() != FL_Escape ) {
        exit( 0 );
    }
}
void searchQueryCallback( Fl_Widget*, void* ) {
    fprintf( stderr, "in Query suchen \n" ) ;
}
void searchQueryAndReplaceCallback( Fl_Widget*, void* ) {
    fprintf( stderr, "in Query suchen und ersetzen\n" ) ;
}
void editSmartStringsCallback( Fl_Widget*, void* ) {
    fprintf( stderr, "Smart Strings bearbeiten\n" ) ;
}
void editOptionsCallback( Fl_Widget*, void* ) {
    fprintf( stderr, "bearbeite Optionen \n" ) ;
}
void generateSqlCallback( Fl_Widget*, void* ) {
    fprintf( stderr, "generiere SQL für Tabelle \n" ) ;
}
void toUpperCaseCallback( Fl_Widget*, void* ) {
    fprintf( stderr, "Query in Großbuchstaben \n" ) ;
}

////////////// Tab Selection Callback
Fl_Tabs *_pSelected = NULL;
void tabSelected( Fl_Widget* w, void* u ) {
    if( _pSelected ) {
        _pSelected->selection_color( FL_BACKGROUND_COLOR );
    }
    Fl_Tabs *tabs = (Fl_Tabs*)w;
    tabs->selection_color( FL_YELLOW );
    _pSelected = tabs;
    fprintf( stderr, "Tab selected \n" ) ;
}

/////////////// Alle Menu Items des Hauptmenüs

Fl_Menu_Item mainMenu[] = {
    {"&Query", FL_ALT+ 'q', NULL, NULL, FL_SUBMENU },
        {"&Neu", FL_ALT+ 'n', NULL, NULL, FL_SUBMENU },
            {"&Query", FL_ALT+ 'q', neueQueryCallback, NULL },
            {"&Recherche",FL_ALT+ 'r', neueRechercheCallback, NULL },
            {0},
        {"&Öffnen", FL_CTRL+ 'o', openQueryCallback, NULL },
        {"&Zuletzt geöffnet", NULL, NULL, NULL, FL_SUBMENU },
            {0},
        {"&Speichern", FL_CTRL+ 's', speichernQueryCallback, NULL },
        {"Speichern &als...", FL_CTRL+ 'a', speichernQueryAlsCallback, NULL, FL_MENU_DIVIDER },
        {"Ausfüh&ren", FL_CTRL+ 'r', runQueryCallback, NULL, FL_MENU_DIVIDER },
        {"Exportieren nach Excel", NULL, excelExportCallback, NULL, FL_MENU_DIVIDER },
        {"B&eenden", FL_CTRL+ 'e', beendenCallback, NULL},
        {0},
    {"B&earbeiten", FL_ALT+'e', NULL, NULL, FL_SUBMENU },
        {"Suchen...", FL_CTRL+ 'f', searchQueryCallback, NULL},
        {"Suchen und Ersetzen...", FL_CTRL+ 'h', searchQueryAndReplaceCallback, NULL, FL_MENU_DIVIDER},
        {"Smart Strings...", NULL, editSmartStringsCallback, NULL, FL_MENU_DIVIDER },
        {"Optionen", NULL, editOptionsCallback, NULL},
        {0},
     {"E&xtras", FL_ALT+'x', NULL, NULL, FL_SUBMENU },
        {"Select für Tabelle generieren...", NULL, generateSqlCallback, NULL},
        {"Query in Großbuchstaben umwandeln", NULL, toUpperCaseCallback, NULL},
        {0},
    {0 }
};

int main( ) {
    int X = 100, Y = 50, W = 800, H = 800, W_RIGHT_TILE = 150;
    int H_MENUBAR = 25, H_TOOLBAR = 25, H_STATUSBAR = 24;
    
    Fl_Double_Window *win = new Fl_Double_Window( X, Y, W, H, "FastSQL" );
    win->callback( beendenCallback );
    
    //////// MenuBar
    Fl_Menu_Bar *menuBar = new Fl_Menu_Bar( 0, 0, W, H_MENUBAR );
    menuBar->box( FL_FLAT_BOX );
    menuBar->color( MYBACKCOLOR );
    menuBar->menu( mainMenu );
    
    ////////// ToolBar
    Fl_Group *pToolBar = new Fl_Group( 0, menuBar->y() + menuBar->h(), W, H_TOOLBAR );
    pToolBar->box( FL_FLAT_BOX );
    pToolBar->color( fl_lighter( MYBACKCOLOR ) );
    pToolBar->end();
    
    ////////// Main-Tile
    Fl_Tile *pMain = new Fl_Tile( 0+1, pToolBar->y() + pToolBar->h(), W-2, H-(H_MENUBAR + H_TOOLBAR + H_STATUSBAR) );
    
    ////////// Left TabsTile containing 4 Tabs areas
    Fl_Tile *pTabsTile = new Fl_Tile( pMain->x(), pMain->y(), pMain->w() - W_RIGHT_TILE, pMain->h() );
    
    ///////////////////// Tabs links oben
    Fl_Group *pContTopLeft = new Fl_Group( pTabsTile->x(), pTabsTile->y(), pTabsTile->w()/2, pTabsTile->h()/2 );
    pContTopLeft->box( FL_DOWN_BOX );
        Fl_Tabs *pTopLeft = new Fl_Tabs( pTabsTile->x(), pTabsTile->y(), pTabsTile->w()/2, pTabsTile->h()/2 );
//        pTopLeft->selection_color( FL_YELLOW );
        pTopLeft->callback( tabSelected );
            Fl_Group *p = new Fl_Group( pTopLeft->x(), pTopLeft->y() + 25, pTopLeft->w(), pTopLeft->h() - 25, "Tab 1" );
            p->box( FL_DOWN_BOX );
            p->end();
            Fl_Group::current()->resizable( p );
            Fl_Group *p2 = new Fl_Group( pTopLeft->x(), pTopLeft->y() + 25, pTopLeft->w(), pTopLeft->h() - 25, "Tab 2" );
            p2->box( FL_DOWN_BOX );
            p2->end();
        pTopLeft->end();
        
    pContTopLeft->end();
    
    
    ///////////////////// Tabs rechts oben
    Fl_Group *pContTopRight = new Fl_Group( pTopLeft->x() + pTopLeft->w(), pTopLeft->y(), pTabsTile->w() - pTopLeft->w(), pTopLeft->h() );
    pContTopRight->box( FL_DOWN_BOX );
        Fl_Tabs *pTopRight = new Fl_Tabs( pTopLeft->x() + pTopLeft->w(), pTopLeft->y(), pTabsTile->w() - pTopLeft->w(), pTopLeft->h() );
//        pTopRight->selection_color( FL_YELLOW );
        pTopRight->callback( tabSelected );
            Fl_Group *p3 = new Fl_Group( pTopRight->x(), pTopRight->y() + 25, pTopRight->w(), pTopRight->h() - 25, "Tab 2" );
            p3->box( FL_DOWN_BOX );
            p3->end();
            Fl_Group::current()->resizable( p3 );
        pTopRight->end();
    pContTopRight->end();
    
    ///////////////////// Tabs links unten
    Fl_Group *pContBotLeft = new Fl_Group( pTopLeft->x(), pTopLeft->y() + pTopLeft->h(), pTopLeft->w(), pTabsTile->h() - pTopLeft->h() );
    pContBotLeft->box( FL_DOWN_BOX );
        Fl_Tabs *pBotLeft = new Fl_Tabs( pTopLeft->x(), pTopLeft->y() + pTopLeft->h(), pTopLeft->w(), pTabsTile->h() - pTopLeft->h() );
//        pBotLeft->selection_color( FL_YELLOW );
            Fl_Group *p4 = new Fl_Group( pBotLeft->x(), pBotLeft->y() + 25, pBotLeft->w(), pBotLeft->h() - 25, "Tab 4" );
            p4->box( FL_DOWN_BOX );
            p4->end();
            Fl_Group::current()->resizable( p4 );
        pBotLeft->end();
    pContBotLeft->end();
    
    ///////////////////// Tabs rechts unten
    Fl_Group *pContBotRight = new Fl_Group( pTopRight->x(), pBotLeft->y(), pTopRight->w(), pBotLeft->h() );
    pContBotRight->box( FL_DOWN_BOX );
        Fl_Tabs *pBotRight = new Fl_Tabs( pTopRight->x(), pBotLeft->y(), pTopRight->w(), pBotLeft->h() );
//        pBotRight->selection_color( FL_YELLOW );
            Fl_Group *p5 = new Fl_Group( pBotRight->x(), pBotRight->y() + 25, pBotRight->w(), pBotRight->h() - 25, "Tab 5" );
            p5->box( FL_DOWN_BOX );
            p5->end();
            Fl_Group::current()->resizable( p5 );
        pBotRight->end();
    pContBotRight->end();
    
    pTabsTile->end();
    //Fl_Group::current()->resizable( pTabsTile );
    
    fprintf( stderr, "tabsTile: %d, %d, %d, %d\n", pTabsTile->x(), pTabsTile->y(), pTabsTile->w(), pTabsTile->h() );
    fprintf( stderr, "topLeft: %d, %d, %d, %d\n", pTopLeft->x(), pTopLeft->y(), pTopLeft->w(), pTopLeft->h() );
    fprintf( stderr, "topRight1: %d, %d, %d, %d\n", pTopRight->x(), pTopRight->y(), pTopRight->w(), pTopRight->h() );
    fprintf( stderr, "botLeft: %d, %d, %d, %d\n", pBotLeft->x(), pBotLeft->y(), pBotLeft->w(), pBotLeft->h() );
    fprintf( stderr, "botRight: %d, %d, %d, %d\n", pBotRight->x(), pBotRight->y(), pBotRight->w(), pBotRight->h() );
    
    /////////// Right Tile containing Database-Explorer
    Fl_Tile *pRight = new Fl_Tile( pTabsTile->x() + pTabsTile->w(), pTabsTile->y(), W_RIGHT_TILE, pTabsTile->h() );
    pRight->box( FL_DOWN_BOX );
    pRight->color( FL_WHITE );
    pRight->end();
    
    pMain->end();
    
    ///////// StatusBar
    Fl_Group *pStatusBar = new Fl_Group( 0+1, pMain->y() + pMain->h(), W-2, H_STATUSBAR );
    pStatusBar->box( FL_FLAT_BOX );
    pStatusBar->color( MYBACKCOLOR );
    pStatusBar->label( "Bereit." );
    pStatusBar->align( FL_ALIGN_LEFT | FL_ALIGN_INSIDE );
    pStatusBar->end();
    
    win->end( );
    win->resizable( pTabsTile );

    win->show( );

    return Fl::run( );
}