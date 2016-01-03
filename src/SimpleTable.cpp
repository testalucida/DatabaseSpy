/* 
 * File:   SimpleTable.cpp
 * Author: max
 * 
 * Created on 22. März 2015, 16:43
 */

#include "SimpleTable.h"

#include <FL/fl_draw.H>

using namespace my;

SimpleTable::SimpleTable( int X, int Y, int W, int H, const char* L )
: Fl_Table( X, Y, W, H, L ) 
{
//    box( FL_FLAT_BOX );
//    color( fl_lighter( FL_LIGHT2 ) );
    row_header_color( FL_LIGHT1 | FL_GRAY );
    col_header_color( FL_LIGHT1 | FL_GRAY );
    callback( &event_callback, (void*) this );
    when( FL_WHEN_NOT_CHANGED | when( ) );
 
    end( );
    
    set_selection( 0, 0, 0, 0 );
}

void SimpleTable::setTableData( my::DataTablePtr pDataTable ) {
    _pData = pDataTable;
    rows( _pData->getRowCount() );
	cols( _pData->getColumnCount() );
    redraw();
}

int SimpleTable::handle( int evt ) {
    int rc = Fl_Table::handle( evt );
    switch( evt ) {
        case FL_PUSH:
            if( Fl::focus() != this ) {
                Fl::focus( this );
            }
            break;
        default:
            break;
    }
    
    return rc;
}

bool SimpleTable::isNothingSelected() {
    int x1, y1, x2, y2;
    get_selection( x1, y1, x2, y2 );
    return x1 < 0 && y1 < 0 && x2 < 0 && y2 < 0;
}

/** Handle drawing all cells in table */
void SimpleTable::draw_cell( TableContext context, int R, int C, int X, int Y, int W, int H ) {
    switch( context ) {
        case CONTEXT_STARTPAGE: // table about to redraw
            break;

        case CONTEXT_COL_HEADER: // table wants us to draw a column heading (C is column)
         
            fl_font( FL_HELVETICA | FL_BOLD, 14 ); // set font for heading to bold
            fl_push_clip( X-1, Y, W, H ); // clip region for text
        {
            fl_draw_box( FL_FLAT_BOX, X, Y, W, H, col_header_color( ) );
            //draw a vertical line between columns and a downsided horizontal one
            fl_color ( FL_GRAY );
            fl_line( X-1, Y, X-1, Y+H-1, X+W, Y+H-1 );
            
            if( _pData ) {
                fl_color( FL_BLACK );
                fl_draw( _pData->getColumnHeader( C ), X, Y, W, H, FL_ALIGN_CENTER );
            }
        }
            fl_pop_clip( );
            return;

        case CONTEXT_ROW_HEADER: // table wants us to draw a row heading (R is row)
            // don't draw this cell if it's being edited
//            if( context_edit == context && R == row_edit && input->visible( ) ) {
//                return;
//            }
            fl_font( FL_HELVETICA | FL_BOLD, 14 ); // set font for row heading to bold
            fl_push_clip( X, Y-1, W+1, H );
        {
            fl_draw_box( FL_FLAT_BOX, X, Y, W, H, row_header_color( ) );
            //draw horizontal line between rows and a vertical right sided line
            fl_color ( FL_GRAY );
            fl_line( X, Y-1, X+W-1, Y-1, X+W-1, Y+H );
    
            if( _pData ) {
                fl_color( FL_BLACK );
                fl_draw( _pData->getRowHeader( R ), X, Y, W, H, FL_ALIGN_CENTER );
            }
        }
            fl_pop_clip( );
            return;

        case CONTEXT_CELL:
        { // table wants us to draw a cell
            
            fl_push_clip( X-1, Y-1, W, H );
            
            // Background
            int highlight = is_selected( R, C );
            fl_draw_box( FL_THIN_UP_BOX, X-1, Y-1, W+2, H+2, highlight ? FL_YELLOW : FL_WHITE );
            
            // Text
            //fl_push_clip( X + 3, Y + 3, W - 6, H - 6 );
            {
                if( _pData ) {
                    fl_color( FL_BLACK );
                    fl_font( FL_HELVETICA, 14 ); // ..in regular font
                    fl_draw( _pData->getValue( R, C ), X + 3, Y + 3, W - 6, H - 6, FL_ALIGN_RIGHT );
                }
            }
            fl_pop_clip( );
            return;
        }

        case CONTEXT_RC_RESIZE: // table resizing rows or columns
           
            return;

        default:
            return;
    }
}


/** Callback whenever someone clicks on different parts of the table */
void SimpleTable::event_callback2( ) {
    int R = callback_row( );
    int C = callback_col( );
    TableContext context = callback_context( );

    switch( context ) {
        case CONTEXT_ROW_HEADER:
            if( isNothingSelected() ) {
                set_selection( R, 1, R, 1 );
                redraw();
            }
            break;
        case CONTEXT_COL_HEADER:
            break;
        case CONTEXT_CELL:
        { // A table event occurred on a cell
            switch( Fl::event( ) ) { // see what FLTK event caused it
                case FL_PUSH: // mouse click?
                    
                    return;

                case FL_KEYBOARD: // key press in table?
                    
                    return;
            }
            return;
        }

        case CONTEXT_TABLE: // A table event occurred on dead zone in table
            
            return;

        default:
            return;
    }
}