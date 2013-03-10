// -*- mode: c++; indent-tabs-mode: t; tab-width: 4; c-basic-offset: 4 -*-
#include "mrb_level_player.h"
#include "mrb_animated_sprite.h"
#include "../../level/level_player.h"

using namespace SMC;

// Extern
struct RClass* SMC::Scripting::p_rcLevel_Player     = NULL;
struct mrb_data_type SMC::Scripting::rtLevel_Player = {"LevelPlayer", NULL};

static mrb_value Kill(mrb_state* p_state, mrb_value self)
{
	pLevel_Player->DownGrade(true);
	return mrb_nil_value();
}

void SMC::Scripting::Init_Level_Player(mrb_state* p_state)
{
	p_rcLevel_Player = mrb_define_class(p_state, "LevelPlayer", p_rcAnimated_Sprite);
	MRB_SET_INSTANCE_TT(p_rcLevel_Player, MRB_TT_DATA);

	// Make the Player global the only instance of LevelPlayer
	mrb_define_const(p_state, p_state->object_class, "Player", pLevel_Player->Create_MRuby_Object(p_state));

	// Forbid creating new instances of LevelPlayer
	mrb_undef_class_method(p_state, p_rcLevel_Player, "new");

	// Normal methods
	mrb_define_method(p_state, p_rcLevel_Player, "kill!", Kill, ARGS_NONE());
}