/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ResultGroup.cpp
 * Author: max
 * 
 * Created on 1. Januar 2016, 12:30
 */

#include "ResultGroup.h"

#include <FL/Fl_Tile.H>

#include <flx/Flx_Table.h>
#include <my/TableData.h>

#include <cassert>

using namespace flx;
using namespace my;
using namespace std;

ResultGroup::ResultGroup( int x, int y, int w, int h ) 
: Fl_Group( x, y, w, h )
{
    int W_HEADER = 300, W_DATA = w - W_HEADER;
    if( W_DATA <= 0 ) {
        W_HEADER = w / 2;
        W_DATA = w - W_HEADER;
    }
    
    box( FL_DOWN_BOX );
    Fl_Tile *pTile = new Fl_Tile( x, y, w, h );
    _pHeaderTbl = new Flx_Table( x, y, W_HEADER, h );
    _pDataTbl = new Flx_Table( x + W_HEADER, y, W_DATA, h );
    pTile->end();
}

void ResultGroup::setResult( shared_ptr<my::TableData> result ) {
    _pHeaderTbl->setTableData( result );
    /*
     Diese Spalten soll die Header-Tabelle enthalten, alle anderen werden auf
     Spaltenbreite 0 gesetzt:
        ibmsnap_commitseq char(10) for bit data not null,
        ibmsnap_intentseq char(10) for bit data not null,
        ibmsnap_operation char(1) not null,
        ibmsnap_logmarker timestamp 
     */
    for( int c = 4, cmax = result->getColumnCount(); c < cmax; c++ ) {
        _pHeaderTbl->setColumnWidthRelative( c, 0 );
    }
    
    /*
     Die Datentabelle enthält alle Spalten der operativen Tabelle.
     Die ersten 4 IBMSNAP_xxx-Spalten werden auf Spaltenbreite 0 gesetzt.
     */
    _pDataTbl->setTableData( result );
    for( int c = 0; c < 4; c++ ) {
        _pDataTbl->setColumnWidthRelative( c, 0 );
    }
}

ResultGroup::~ResultGroup( ) {
}

