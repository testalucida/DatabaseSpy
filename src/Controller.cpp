/* 
 * File:   Controller.cpp
 * Author: max
 * 
 * Created on 1. Januar 2016, 19:10
 */

#include "Controller.h"

#include "ToolBarGroup.h"
#include "SearchCriteriaGroup.h"
#include "ResultGroup.h"

Controller::Controller( ToolBarGroup &tb, SearchCriteriaGroup &sc, ResultGroup &rg ) 
: _toolBar( tb )
, _searchCriteria( sc )
, _result( rg )
{
    _toolBar.callback( staticToolbarCallback, this );
}

void Controller::init() {
    //Laden der Combobox mit den V2-Tabellen
}

void Controller::toolbarCallback( Event e ) {
    fprintf( stderr, "Action = %d\n", e );
}

void Controller::staticToolbarCallback( Event e, void *pThis ) {
    ((Controller*)pThis)->toolbarCallback( e );
}



