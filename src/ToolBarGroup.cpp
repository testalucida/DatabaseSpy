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
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Pixmap.H>
#include "../images/start.xpm"
#include "../images/start_deact.xpm"
#include "../images/details2.xpm"
#include "../images/details2_deact.xpm"
#include "../images/filter.xpm"
#include "../images/filter_deact.xpm"
#include <FL/Fl_Box.H>

ToolBarGroup::ToolBarGroup( int x, int y, int w, Fl_Color colr )
: Fl_Group( x, y, w, getPreferredHeight() )
, _callback( 0 )
, _pUserData( NULL )
{
    box( FL_FLAT_BOX );
    color( fl_lighter( colr ) );
    _pStartBtn = createButton( 10, start_xpm, start_deact_xpm, "V2-Recherche starten" );
    _pTransBtn = createButton( _pStartBtn->x() + _pStartBtn->w() + 10, details2_xpm, details2_deact_xpm, 
                               "Alle Änderungen der gleichen Transaktion anzeigen" );
    //"Separator":
    Fl_Box *pBox = new Fl_Box( _pTransBtn->x() + _pTransBtn->w() + 10,
                               _pTransBtn->y() + 5,
                               2,
                               _pTransBtn->h() - 10 );
    pBox->box( FL_DOWN_BOX );
    
    _pFilterBtn = (Fl_Toggle_Button*)createButton( pBox->x() + pBox->w()+ 10, filter_xpm, filter_deact_xpm, 
                               "Nur geänderte Spalten anzeigen", true );
    
    //Box, die verhindert, dass sich die Buttons beim resize verschieben:
    int wdummy = w - ( _pFilterBtn->x() + _pFilterBtn->w() );
    Fl_Box *pDummy = new Fl_Box( _pFilterBtn->x() + _pFilterBtn->w(), _pFilterBtn->y(), wdummy, 1 );
    end();
    resizable( pDummy );
}

Fl_Button* ToolBarGroup::createButton( int x, const char **xpm, const char **xpm_deact, const char *tooltip, bool toggle ) {
    Fl_Button *pBtn = toggle ? new Fl_Toggle_Button( x, y()+2, 36, 36 ) : new Fl_Button( x, y()+2, 36, 36 );
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
    pBtn->callback( staticOnAction, this );
    
    return pBtn;
}

void ToolBarGroup::staticOnAction( Fl_Widget *w, void *pThis ) {
    ((ToolBarGroup*)pThis)->onAction( (Fl_Button*)w);
}

void ToolBarGroup::onAction( Fl_Button *pBtn ) {
    if( _callback != 0 ) {
        Event e;
        if( pBtn == _pStartBtn ) e = EVT_START_SEARCH;
        else if( pBtn == _pTransBtn ) e = EVT_TRANS_DETAILS;
        else if( pBtn == _pFilterBtn ) {            
            e = ( _pFilterBtn->value() == 1 ) ? EVT_FILTER_ON :EVT_FILTER_OFF;
        }
        else e = EVT_UNK;
        
        (_callback)( e, _pUserData );
    }
}

void ToolBarGroup::callback( ToolBarCallback tbc, void *pUserData )  {
    _callback = tbc;
    _pUserData = pUserData;
}

void ToolBarGroup::activate( Event e, bool active ) {
    Fl_Button *pBtn;
    
    switch( e ) {
        case EVT_START_SEARCH:
            pBtn = _pStartBtn;
            break;
        case EVT_TRANS_DETAILS:
            pBtn = _pTransBtn;
            break;
        case EVT_FILTER_ON:
            pBtn = _pFilterBtn;
            break;
        default:
            return;
    }
    
    if( active ) pBtn->activate();
    else pBtn->deactivate();
}