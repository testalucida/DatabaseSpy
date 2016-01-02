/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controller.h
 * Author: max
 *
 * Created on 1. Januar 2016, 19:10
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "events.h"
#include "callbacks.h"
#include "SearchCriteriaModel.h"

class ToolBarGroup;
class SearchCriteriaGroup;
class ResultGroup;

class Controller {
public:
    Controller( ToolBarGroup &, SearchCriteriaGroup &, ResultGroup & );
    void init();
    static void staticToolbarCallback( Event e, void *pUserData );
    void toolbarCallback( Event e );
private:
    ToolBarGroup&_toolBar;
    SearchCriteriaGroup& _searchCriteria; 
    ResultGroup& _result; 
    SearchCriteriaModel _searchModel;
};

#endif /* CONTROLLER_H */

