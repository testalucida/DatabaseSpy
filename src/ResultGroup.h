/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ResultGroup.h
 * Author: max
 *
 * Created on 1. Januar 2016, 12:30
 */

#ifndef RESULTGROUP_H
#define RESULTGROUP_H

#include <FL/Fl_Group.H>
#include <memory>

namespace flx {
    class Flx_Table;
}
namespace my {
    class TableData;
}

class ResultGroup : public Fl_Group {
public:
    ResultGroup( int x, int y, int w, int h );
    void setResult( std::shared_ptr<my::TableData> result );
    ~ResultGroup();
private:
    flx::Flx_Table *_pHeaderTbl; //enthält die IBM-Spalten IBMSNAP_LOGMARKER etc.
    flx::Flx_Table *_pDataTbl; //enthält die Spalten der operativen Tabelle
};

#endif /* RESULTGROUP_H */

