/*
  SpresenseLteTwitter.h - Porting for Spresense LTE board.
*/
/*
  Stewitter.h - Arduino library to Post messages to Twitter with OAuth.
  Copyright (c) arms22 2010 - 2012. All right reserved.
*/
/*
  Twitter.h - Arduino library to Post messages to Twitter.
  Copyright (c) NeoCat 2009. All right reserved.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#ifndef SpresenseLteTwitter_H
#define SpresenseLteTwitter_H

#include <Arduino.h>
#include <LTE.h>

class SpresenseLteTwitter
{
private:
    LTE lte;
    LTEClient client;
    String httpBody;
    const char *token;
    int statusCode;
    uint8_t parseStatus;
public:
    SpresenseLteTwitter(const char *token);
    void begin(const char* apn, const char* user, const char* pass);
    bool post(const char *msg);
    bool lastMention(void);
    bool checkStatus(Print *debug = NULL);
    int  wait(Print *debug = NULL);
    int  status(void) { return statusCode; }
    String& response(void) { return httpBody; }
};

#endif //SpresenseLteTwitter_H
