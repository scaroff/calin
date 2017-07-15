# calin/python/plotting.py -- Stephen Fegan -- 2017-07-15
#
# Plotting of simulation elements
#
# Copyright 2017, Stephen Fegan <sfegan@llr.in2p3.fr>
# LLR, Ecole polytechnique, CNRS/IN2P3, Universite Paris-Saclay
#
# This file is part of "calin"
#
# "calin" is free software: you can redistribute it and/or modify it under the
# terms of the GNU General Public License version 2 or later, as published by
# the Free Software Foundation.
#
# "calin" is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
# A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

import matplotlib.pyplot as plt
import matplotlib.collections
import numpy as np

def plot_mirrors(scope, label_hex_id=False, ax_in=None):
    max_xy = 0
    pix = []
    for imirror in range(scope.numMirrors()):
        mirror = scope.mirror(imirror)
        vx = []
        vy = []
        for i in range(6):
            v = mirror.cornerInReflectorCoords(i,scope.facetSize())
            vx.append(v[0])
            vy.append(v[2])
        vx = np.asarray(vx)
        vy = np.asarray(vy)
        vv = np.zeros((len(vx),2))
        vv[:,0] = vx
        vv[:,1] = vy
        max_xy = max(max_xy, max(abs(vx)), max(abs(vy)))
        pix.append(plt.Polygon(vv,closed=True))
    ax = ax_in if ax_in is not None else plt.gca()
    pc = matplotlib.collections.PatchCollection(pix, cmap=matplotlib.cm.jet)
    #pc.set_linewidths(0)
    ax.add_collection(pc)
    ax.axis('square')
    ax.axis(np.asarray([-1,1,-1,1])*1.05*max_xy)
    ax.set_xlabel('X coordinate [cm]')
    ax.set_ylabel('Y coordinate [cm]')
    if(label_hex_id):
        for imirror in range(scope.numMirrors()):
            mirror = scope.mirror(imirror)
            ax.text(mirror.pos()[0], mirror.pos()[2], '%d'%(mirror.hexID()+1),\
                ha='center',va='center')
    return pc
