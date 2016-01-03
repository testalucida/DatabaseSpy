/* 
 * File:   SimpleTable.h
 * Author: max
 *
 * Created on 22. März 2015, 16:43
 */

#include <FL/Fl_Table.H>
#include <FL/Fl_Input.H>
//#include <FL/fl_draw.H>

#include <my/TableData.h>

#ifndef SIMPLE_TABLE_H
#define	SIMPLE_TABLE_H

class SimpleTable : public Fl_Table {
public:
    SimpleTable( int X, int Y, int W, int H, const char* L = 0 );
    void setTableData( my::DataTablePtr pDataTable );
    my::DataTablePtr getTableData() { return _pData; }
    int handle( int );
    bool isNothingSelected();
    virtual ~SimpleTable() {};
protected:
    virtual void draw_cell( TableContext context, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0 );
    
    void event_callback2( ); // table's event callback (instance)

    static void event_callback( Fl_Widget*, void *v ) { // table's event callback (static)
        ( (SimpleTable*) v )->event_callback2( );
    }


private:
    my::DataTablePtr _pData;
};

#endif	/* FLX_SPREADSHEET_H */

