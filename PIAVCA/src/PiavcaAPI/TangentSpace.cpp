/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is TangentSpace.cpp.
 *
 * The Initial Developer of the Original Code is Marco (Mark) Gillies.
 * Portions created by the Initial Developer are Copyright (C) Marco Gillies 2008
 * All Rights Reserved.
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */


#include "TangentSpace.h"
#include "PiavcaError.h"
#include "PiavcaCore.h"

using namespace Piavca;

void TangentSpace::calcCoordAxes(const Quat &q)
{
	coordAxes.clear();
	coordAxes.push_back(Quat());
	coordAxes.push_back(Quat());
	coordAxes.push_back(Quat());
	coordAxes.push_back(Quat());

	coordAxes[0] = q;
	if(fabs(q[0]) < 0.0001 && fabs(q[1]) < 0.0001)
	{
		coordAxes[1] = Quat(1.0, 0.0, 0.0, 0.0);
		coordAxes[2] = Quat(0.0, 1.0, 0.0, 0.0);
		coordAxes[3] = Quat(0.0, 0.0, q[3], -q[2]);
		coordAxes[3].normalise();
		return;
	}
	if(fabs(q[2]) < 0.0001 && fabs(q[3]) < 0.0001)
	{
		coordAxes[1] = Quat(q[1], -q[0], 0.0, 0.0);
		coordAxes[1].normalise();
		coordAxes[2] = Quat(0.0, 0.0, 1.0, 0.0);
		coordAxes[3] = Quat(0.0, 0.0, 0.0, 1.0);
		return;
	}

	coordAxes[1] = Quat(q[1], -q[0], 0.0, 0.0);
	coordAxes[1].normalise();
	coordAxes[2] = Quat(0.0, 0.0, q[3], -q[2]);
	coordAxes[2].normalise();
	coordAxes[3] = cross(coordAxes[0], coordAxes[1], coordAxes[2]);
	coordAxes[3].normalise();
};

float TangentSpace::dot(const Quat &q1, const Quat &q2)
{
	return q1[0]*q2[0] + q1[1]*q2[1] + q1[2]*q2[2] + q1[3]*q2[3];
}

Quat TangentSpace::cross(const Quat &q1, const Quat &q2, const Quat &q3)
{
		Quat q;
		q[0] =	 q1[1]*(q2[2]*q3[3] - q2[3]*q3[2]) ;
		q[0] -=  q1[2]*(q2[1]*q3[3] - q2[3]*q3[1]) ;
		q[0] +=  q1[3]*(q2[1]*q3[2] - q2[2]*q3[1]);

		q[1] =	-q1[0]*(q2[2]*q3[3] -  q2[3]*q3[2]) ;
		q[1] +=  q1[2]*(q2[0]*q3[3] - q2[3]*q3[0]) ;
		q[1] -=  q1[3]*(q2[0]*q3[2] - q2[2]*q3[0]);

		q[2] =	 q1[0]*(q2[1]*q3[3] - q2[3]*q3[1]) ;
		q[2] -=  q1[1]*(q2[0]*q3[3] - q2[3]*q3[0]) ;
		q[2] +=  q1[3]*(q2[1]*q3[0] - q2[0]*q3[1]);

		q[3] =	-q1[0]*(q2[1]*q3[2] - q2[2]*q3[1]) ;
		q[3] +=  q1[1]*(q2[0]*q3[2] - q2[2]*q3[0]) ;
		q[3] -=  q1[2]*(q2[0]*q3[1] - q2[1]*q3[0]);
		return q;
}


TangentSpace::TangentSpace(const Quat &q)
{
	calcCoordAxes(q);
}
		
TangentSpace::TangentSpace(std::vector<Quat> qs)
{
	Quat q(0.0, 0.0, 0.0, 0.0);
	for (unsigned int i =0; i < qs.size(); i++)
	{
		Quat val = qs[i];
		if(val[0] < 0.0)
			 val = Quat(-val[0], -val[1], -val[2], -val[3]);
		q[0] += val[0]/qs.size();
		q[1] += val[1]/qs.size();
		q[2] += val[2]/qs.size();
		q[3] += val[3]/qs.size();
	}
	q.normalise();

	Vec u(0.0, 0.0, 0.0);
	int count = 0;
	while (true)
	{
		if (count > 500 )
		{
			//print "error", u, u.mag()
			if (u.mag() < 0.001)
				break;
			Piavca::Error(_T("exceeded maximum iterations"));
		}
		count += 1;

		centre = q;
		calcCoordAxes(q);
		u = Vec();
		for (unsigned int i =0; i < qs.size(); i++)
		{
			Vec val = logMap(qs[i]);
			u += val/qs.size();
		}
		q = expMap(u);
		//print "curent iter",  u, q

		if (u.mag() < 0.0005)
			break;
	};
	calcCoordAxes(q);
}
		
TangentSpace::TangentSpace(const TangentSpace &ts)
{
	coordAxes.push_back(ts.coordAxes[0]);
	coordAxes.push_back(ts.coordAxes[0]);
	coordAxes.push_back(ts.coordAxes[0]);
	coordAxes.push_back(ts.coordAxes[0]);
	centre = ts.centre;
}

Quat TangentSpace::expMap(const Vec  &p)
{
	float theta = p.mag();
	//float theta = Quat::spherical_distance(centre, p);

	float convFactor = 0.0;
	if(fabs(theta) < 0.00001)
		convFactor = 0.0;
	else
		convFactor = sin(theta)/theta;

	Quat p1;
	//Quat p2;

	p1[0] = cos (theta);
	p1[1] = p[0]*convFactor;
	p1[2] = p[1]*convFactor;
	p1[3] = p[2]*convFactor;

	p1 = p1*centre;

	//p2[0] = p1[0] + coordAxes[0][0];
	//p2[1] = p1[1] + coordAxes[0][1];
	//p2[2] = p1[2] + coordAxes[0][2];
	//p2[3] = p1[3] + coordAxes[0][3];

	//p2[0]  = p1[0]*coordAxes[0][0] + p1[1]*coordAxes[1][0]; 
	//p2[0] += p1[2]*coordAxes[2][0] + p1[3]*coordAxes[3][0];

	//p2[1]  = p1[0]*coordAxes[0][1] + p1[1]*coordAxes[1][1]; 
	//p2[1] += p1[2]*coordAxes[2][1] + p1[3]*coordAxes[3][1];

	//p2[2]  = p1[0]*coordAxes[0][2] + p1[1]*coordAxes[1][2]; 
	//p2[2] += p1[2]*coordAxes[2][2] + p1[3]*coordAxes[3][2];

	//p2[3]  = p1[0]*coordAxes[0][3] + p1[1]*coordAxes[1][3]; 
	//p2[3] += p1[2]*coordAxes[2][3] + p1[3]*coordAxes[3][3];

	return p1;
}
		
Vec  TangentSpace::logMap(const Quat &q)
{
	Quat p1 = q/centre;
	if(p1[0] < 0.0)
		p1 = Quat(-p1[0], -p1[1], -p1[2], -p1[3]);
	
	Quat p2 = p1;
	//Quat p2(dot(p1, coordAxes[0]),
	//	dot(p1, coordAxes[1]),
	//	dot(p1, coordAxes[2]),
	//	dot(p1, coordAxes[3]));
	//Quat p2(p1[0] - coordAxes[0][0],
	//	p1[1] - coordAxes[0][1],
	//	p1[2] - coordAxes[0][2],
	//	p1[3] - coordAxes[0][3]);
	p2.normalise();

	float theta = acos(p2[0]);
	float convFactor = 0.0;
	if(fabs(theta) < 0.0001)
		convFactor = 0.0;
	else
		convFactor = theta/sin(theta);
	return Vec(p2[1]*convFactor, p2[2]*convFactor, p2[3]*convFactor);
}

Quat TangentSpace::mean()
{
	return coordAxes[0];
}

std::vector<TangentSpace> TangentSpace::calculateTangentSpacesFromMotionAverages(std::vector<Motion *> motions, float time)
{
	std::vector <TangentSpace> result;
	for (unsigned int trackid = 0; trackid < Piavca::Core::getCore()->getMaxJointId()+1; trackid++)
	{
		std::vector<Quat> qs;
		for (unsigned int i = 0; i < motions.size(); i++)
		{
			if (motions[i] && !motions[i]->isNull(trackid) && (motions[i]->getTrackType(trackid) & QUAT_TYPE))
			{
				qs.push_back(motions[i]->getQuatValueAtTime(trackid, time));
			}
		};
		if (qs.size() > 0)
		{
			result.push_back(TangentSpace(qs));
		}
		else
		{
			result.push_back(TangentSpace());
		}
	};
	return result;
}