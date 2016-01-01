/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ToolBarGroup.cpp
 * Author: max
 * 
 * Created on 31. Dezember 2015, 15:11
 */

#include "ToolBarGroup.h"

#include <FL/Fl_Button.H>
#include <FL/Fl_Pixmap.H>
#include "../images/start.xpm"
#include "../images/start_deact.xpm"
#include "../images/details2.xpm"
#include "../images/details2_deact.xpm"

ToolBarGroup::ToolBarGroup( int x, int y, int w, Fl_Color colr )
: Fl_Group( x, y, w, getPreferredHeight() )
{
    box( FL_FLAT_BOX );
    color( fl_lighter( colr ) );
    _pStartBtn = createButton( 10, start_xpm, start_deact_xpm, "V2-Recherche starten" );
    _pTransBtn = createButton( _pStartBtn->x() + _pStartBtn->w() + 10, details2_xpm, details2_deact_xpm, 
                               "Alle Änderungen der gleichen Transaktion anzeigen" );
    end();
}

Fl_Button* ToolBarGroup::createButton( int x, const char **xpm, const char **xpm_deact, const char *tooltip ) {
    Fl_Button *pBtn = new Fl_Button( x, y()+2, 36, 36 );
    pBtn->box( FL_FLAT_BOX );
    pBtn->down_box( FL_DOWN_BOX );
    pBtn->color( color() );
    pBtn->visible_focus( 0 );
    pBtn->deactivate();
    Fl_Pixmap *pixmap = new Fl_Pixmap( xpm );
    pBtn->image( pixmap );
    pixmap = new Fl_Pixmap( xpm_deact );
    pBtn->deimage( pixmap );
    pBtn->tooltip( tooltip );
    return pBtn;
}
