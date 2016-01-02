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

#include <my/datetime.h>

using namespace my;
using namespace std;

Controller::Controller( ToolBarGroup &tb, SearchCriteriaGroup &sc, ResultGroup &rg ) 
: _toolBar( tb )
, _searchCriteria( sc )
, _result( rg )
{
    _toolBar.callback( staticToolbarCallback, this );
}

void Controller::init() {
    //Laden des SearchModels
    //V2-Tabellen:
    ////////////dummy:
    vector<string> tables;
    tables.push_back( "T2AB" );
    tables.push_back( "T2ADR_ADRN_ADRG" );
    tables.push_back( "T2ANSCHR" );
    tables.push_back( "T2ANW" );
    
    _searchModel.setV2Tables( tables );
    
    //Indexes der V2-Tabellen:
    
    //Suchdatum-Default: 1.11.2002
    _searchModel.setSearchFrom( MyDate( 1, 11, 2001 ) );
    
    _searchCriteria.setModel( _searchModel );
    _toolBar.activate( EVT_START_SEARCH, true );
}

void Controller::toolbarCallback( Event e ) {
    //&fprintf( stderr, "Action = %d\n", e );
       switch( e ) {
        case EVT_START_SEARCH:
            //mit den eingestellten Werten in der Datenbank suchen:
            
            break;
        case EVT_TRANS_DETAILS:
            //mit der Commitsequence, die in der Result-Tabelle selektiert ist,
            //alle Änderungen dieser Commitsequence aus der Datenbank holen:
            
            break;
        case EVT_FILTER_ON:
            //die Spalten in der Result-Tabelle ausblenden, die sich nicht
            //geändert haben:
            
            break;
        case EVT_FILTER_OFF:
            //die ausgeblendeten Spalten wieder einblenden:
            
            break;
        default:
            return;
    }
}

void Controller::staticToolbarCallback( Event e, void *pThis ) {
    ((Controller*)pThis)->toolbarCallback( e );
}



