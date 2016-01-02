/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SearchCriteriaGroup.h
 * Author: max
 *
 * Created on 31. Dezember 2015, 13:21
 */

#ifndef SEARCHCRITERIAGROUP_H
#define SEARCHCRITERIAGROUP_H

#include <FL/Fl_Group.H>

class Fl_Input_Choice;
class Fl_Input;
class Fl_Int_Input;
class Fl_Button;
class SearchCriteriaModel;

namespace flx {
    class Flx_Calendar;
}

class SearchCriteriaGroup : public Fl_Group {
public:
    SearchCriteriaGroup( int x, int y, int w );
    static int getPreferredWidth() { return 850; }
    void setModel( SearchCriteriaModel & );
private:
    static void onShowCalendarStatic( Fl_Widget*, void * );
    void onShowCalendar();
private:
    Fl_Input_Choice *_pTableCombo;
    Fl_Input_Choice *_pColumnCombo;
    Fl_Int_Input *_pColumnValue;
    Fl_Input *_pSearchFrom; //Datum, ab dem gesucht werden soll
    Fl_Button *_pOpenCalendarBtn;
    flx::Flx_Calendar *_pCal;
    SearchCriteriaModel *_pModel;
};

#endif /* SEARCHCRITERIAGROUP_H */

