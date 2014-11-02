/***************************************************************************
 * shell.hpp - loose shells lying around.
 *
 * Copyright © 2014 The SMC Contributors
 ***************************************************************************/
/*
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SMC_SHELL_HPP
#define SMC_SHELL_HPP
#include "turtle.hpp"

namespace SMC {

    class cShell: public cTurtle {
    public:
        cShell(cSprite_Manager* p_sprite_manager);
        cShell(XmlAttributes& attributes, cSprite_Manager* p_sprite_manager);
        virtual ~cShell();
        virtual cShell* Copy() const;

        virtual void Update();
        virtual void Stand_Up();
        virtual void Set_Color(DefaultColor col);

        virtual std::string Create_Name() const;
    protected:
        void Init();
        virtual std::string Get_XML_Type_Name();
    };
}

#endif