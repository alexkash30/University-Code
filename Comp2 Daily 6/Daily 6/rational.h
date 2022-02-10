#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H

typedef void* RATIONAL; //Define handle

RATIONAL ratioanl_init_default(void);
void rational_destroy(RATIONAL* phRational);


#endif