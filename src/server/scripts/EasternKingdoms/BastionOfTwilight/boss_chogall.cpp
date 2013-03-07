/*
 * Copyright (C) 2011-2013 Project SkyFire <http://www.projectskyfire.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

 /*Cho'gall on development, about 0,5% of the script*/
 
 
#include"ScriptPCH.h"
#include"bastion_of_twilight.h"

enum Spells
{
    //Cho'gall
    SPELL_CONSUME_BLOOD_OF_THE_OLD_GOD      = 82630,
    SPELL_CONVERSION                        = 91303,
	SPELL_CORRUPTION_OF_THE_OLD_GOD         = 82361,
	SPELL_DARKENED_CREATIONS                = 82414,
	SPELL_FESTER_BLOOD                      = 82299,
	SPELL_FLAMES_ORDERS                     = 81171,
	SPELL_FURY_OF_CHOGALL                   = 82524,
	SPELL_SHADOWS_ORDERS                    = 81556,
	SPELL_SUMMON_CORRUPTING_ADHERENT        = 81628,
	//Corrupting Adherent
	SPELL_CORRUPTING_CRASH                  = 81685,
	SPELL_DEPRAVITY                         = 81713,
	SPELL_FESTERING_BLOOD                   = 82914,
	SPELL_SPILLED_BLOOD_OF_THE_OLD_GOD      = 81757
};

enum Events
{
    //Yeh.... dudes about it
    EVENT_NONE,
    EVENT_NONE2,
	EVENT_NONE3
};

enum ePhases
{
    PHASE_1   = 1,
    PHASE_2   = 2,
};

class boss_chogall : public CreatureScript
{
public:
    boss_chogall() : CreatureScript("boss_chogall") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_chogallAI (creature);
    }

    struct boss_chogallAI : public ScriptedAI
    {
        boss_chogallAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset() {}

        void EnterCombat(Unit* /*who*/) {}

        void UpdateAI(const uint32 /*diff*/)
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_chogall()
{
    new boss_chogall();
}
