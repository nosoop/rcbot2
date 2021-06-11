#ifndef __BOT_WPT_DIST_H__
#define __BOT_WPT_DIST_H__

#include <array>
#include "bot_waypoint.h"

#define WPT_DIST_VER 0x03

#define BOT_WAYPOINT_DST_EXTENSION "rcd"

class CWaypointDistances
{
public:
	CWaypointDistances()
	{
		m_fSaveTime = 0;
	}

	static float getDistance ( int iFrom, int iTo );

	static inline bool isSet ( int iFrom, int iTo )
	{
		return m_Distances[iFrom][iTo] >= 0;
	}

	static inline void setDistance ( int iFrom, int iTo, float fDist )
	{
		m_Distances[iFrom][iTo] = (int)fDist;
	}

	static void load ();

	static void save ();

	static void reset ()
	{
		for (auto& row: m_Distances) {
			row.fill(0xFF);
		}
	}
private:
	static std::array<std::array<int, CWaypoints::MAX_WAYPOINTS>, CWaypoints::MAX_WAYPOINTS> m_Distances;
	static float m_fSaveTime;

};



#endif