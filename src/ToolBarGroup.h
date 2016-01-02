/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ToolBarGroup.h
 * Author: max
 *
 * Created on 31. Dezember 2015, 15:11
 */

#ifndef TOOLBARGROUP_H
#define TOOLBARGROUP_H

#include <FL/Fl_Group.H>
#include "events.h"
#include "callbacks.h"

class Fl_Button;
class Fl_Toggle_Button;


class ToolBarGroup : public Fl_Group {
public:
    ToolBarGroup( int x, int y, int w, Fl_Color color );
    static int getPreferredHeight() { return 40; }
    void callback( ToolBarCallback, void * );
    void activate( Event e, bool active );
private:
    Fl_Button* createButton( int x, const char **xpm, const char **xpm_deact, const char *tooltip, bool toggle = false );
    static void staticOnAction( Fl_Widget *, void * );
    void onAction( Fl_Button * );
private:
    ToolBarCallback _callback;
    void *_pUserData;
    Fl_Button *_pStartBtn;
    Fl_Button *_pTransBtn;
    Fl_Toggle_Button *_pFilterBtn;
    
};

#endif /* TOOLBARGROUP_H */

