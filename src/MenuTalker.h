/*
Copyright © 2011-2012 Clint Bellanger and morris989

This file is part of FLARE.

FLARE is free software: you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation,
either version 3 of the License, or (at your option) any later version.

FLARE is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
FLARE.  If not, see http://www.gnu.org/licenses/
*/

/**
 * class MenuTalker
 */

#ifndef MENU_TALKER_H
#define MENU_TALKER_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include <string>
#include <sstream>

class CampaignManager;
class NPC;
class WidgetButton;

class MenuTalker {
private:
	CampaignManager *camp;

	void loadGraphics();
	SDL_Surface *background;
	SDL_Surface *portrait;
	SDL_Surface *msg_buffer;
	std::string hero_name;

	int dialog_node;

public:
	MenuTalker(CampaignManager *camp);
	~MenuTalker();

	NPC *npc;
	
	void chooseDialogNode();
	void logic();
	void render();
	void setHero(const std::string& name, const std::string& portrait_filename);
	void createBuffer();
	
	bool visible;
	bool vendor_visible;
	bool has_vendor_button;
	int event_cursor;
	bool accept_lock;

	WidgetButton *advanceButton;
	WidgetButton *closeButton;
	WidgetButton *vendorButton;
	
};

#endif
