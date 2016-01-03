/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   callbacks.h
 * Author: max
 *
 * Created on 2. Januar 2016, 00:12
 */

#ifndef CALLBACKS_H
#define CALLBACKS_H

#include "events.h"
#include <vector>

typedef void ( *ToolBarCallback ) ( Event, void * );

typedef unsigned char byte;
struct ResultSelectionParms {
    int row;
    byte ibmsnap_commitseq[10];
};

typedef void ( *ResultGroupCallback ) ( std::vector<ResultSelectionParms>, void * );

#endif /* CALLBACKS_H */

