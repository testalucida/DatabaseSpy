
/* 
 * File:   SearchCriteriaGroup.cpp
 * Author: max
 * 
 * Created on 31. Dezember 2015, 13:21
 */

#include "SearchCriteriaGroup.h"
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Pixmap.H>
#include <flx/Flx_Calendar.h>
#include "../images/calendar.xpm"

#include <my/datetime.h>


using namespace flx;
using namespace my;

SearchCriteriaGroup::SearchCriteriaGroup( int x, int y, int w ) 
: Fl_Group( x, y, w, 80 )
, _pCal( NULL )
{
    box( FL_DOWN_BOX );
    int H_WIDG = 25, W_COMBO = 180;
    int XSPACE = 5, YSPACE = 5, YTOP = y + 10;
    
    _pTableCombo = new Fl_Input_Choice( x+75, YTOP, W_COMBO, H_WIDG, "Tabelle: " );
    _pColumnCombo = new Fl_Input_Choice( _pTableCombo->x() + _pTableCombo->w() + 170, 
                                         YTOP, W_COMBO, 
                                         H_WIDG, 
                                         "Suchen über Spalte: " );
    _pColumnCombo->tooltip( "Keine Angabe: Selektion aller Änderungen ab Suchdatum" );
    _pColumnValue = new Fl_Int_Input( _pColumnCombo->x(), 
                                      _pColumnCombo->y() + _pColumnCombo->h() + YSPACE, 
                                      W_COMBO - 22, H_WIDG, 
                                      "Spaltenwert: " );
    _pColumnValue->tooltip( "Mussfeld, wenn Suchspalte angegeben" );
    _pSearchFrom = new Fl_Input( _pColumnCombo->x() + _pColumnCombo->w() + 108,
                                 _pColumnCombo->y(),
                                 100, H_WIDG,
                                 "Suchen ab: " );
    _pSearchFrom->tooltip( "Datum, ab dem Änderungen selektiert werden (0 Uhr)" );
    _pOpenCalendarBtn = new Fl_Button( _pSearchFrom->x() + _pSearchFrom->w() + XSPACE,
                                       _pSearchFrom->y(),
                                        _pSearchFrom->h(),
                                        _pSearchFrom->h() );
    Fl_Pixmap *pixmap = new Fl_Pixmap( calendar_xpm );
    _pOpenCalendarBtn->image( pixmap );
    _pOpenCalendarBtn->box( FL_FLAT_BOX );
    _pOpenCalendarBtn->down_box( FL_DOWN_BOX );
    _pOpenCalendarBtn->callback( onShowCalendarStatic, this );
    
    int w_rest = w - (_pOpenCalendarBtn->x() + _pOpenCalendarBtn->w() );
    Fl_Box *pBox = new Fl_Box( _pOpenCalendarBtn->x() + _pOpenCalendarBtn->w(),
                               _pOpenCalendarBtn->y(), w_rest, _pOpenCalendarBtn->h() );
    end();
    resizable( pBox );
}

void SearchCriteriaGroup::onShowCalendar() {
    if( _pCal == NULL ) {
        _pCal = new Flx_Calendar();
    }
    MyDate date = _pCal->show( _pSearchFrom->x() + 10, _pSearchFrom->y() + _pSearchFrom->h() + 5 );
    if( date.IsSet() ) {
        _pSearchFrom->value( date.ToIsoString().c_str() );
    }
}

void SearchCriteriaGroup::onShowCalendarStatic( Fl_Widget*, void *pThis ) {
    ((SearchCriteriaGroup*)pThis)->onShowCalendar();
}


