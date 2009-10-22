/*
 *  PiavcaInterface.h
 *  max.jit.piavca
 *
 *  Created by Marco Gillies on 22/10/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef PIAVCA_INTERFACE_H
#define PIAVCA_INTERFACE_H


void piavcaInit();

void piavcaLoadFile(char *file) ;

void piavcaPlayMotion(char *avatar, char*motion);

void piavcaDraw();


#endif // PIAVCA_INTERFACE_H