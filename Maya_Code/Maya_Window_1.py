import maya.cmds as cmds

#Global Variables
range_global=100
change_global=50
wl_global=1


def make_Cube_spiral(max_range, change, wl):
    
    cube_list = [] #list of all cubes
    
    for num in range(max_range):
        cube = cmds.polyCube() # create the cube
        cube_list.append(cube[0])
        cmds.move(change/2.0, wl*num, 0, cube[0]) # make the spiral climb
        cmds.rotate(0, num*10, 0, cube[0], pivot=[0,0,0]) # make the spiral turn
    
    cmds.group(cube_list) # put all the cubes into a group
    cmds.rename("Cube_Spiral") # rename said group
    
    
def make_Sphere_spiral(max_range, change, wl):
    
    sphere_list = [] #list of all spheres
    
    for num in range(max_range):
        sphere = cmds.polySphere() # create the sphere
        sphere_list.append(sphere[0])
        cmds.move(change/2.0, wl*num, 0, sphere[0])  # make the spiral climb
        cmds.rotate(0, num*10, 0, sphere[0], pivot=[0,0,0]) # make the spiral turn
    
    cmds.group(sphere_list) # put all the spheres into a group
    cmds.rename("Sphere_Spiral") # rename said group


def make_Cylinder_spiral(max_range, change, wl):
    
    cylinder_list = [] #list of all cylinders
    
    for num in range(max_range):
        cylinder = cmds.polyCylinder() # create the cylinder
        cylinder_list.append(cylinder[0])
        cmds.move(change/2.0, wl*num, 0, cylinder[0])  # make the spiral climb
        cmds.rotate(0, num*10, 0, cylinder[0], pivot=[0,0,0]) # make the spiral turn
    
    cmds.group(cylinder_list) # put all the spheres into a group
    cmds.rename("Cylinder_Spiral") # rename said group
    
def make_Cone_spiral(max_range, change, wl):
    
    cone_list = [] #list of all spheres
    
    for num in range(max_range):
        cone = cmds.polyCone() # create the sphere
        cone_list.append(cone[0])
        cmds.move(change/2.0, wl*num, 0, cone[0])  # make the spiral climb
        cmds.rotate(0, num*10, 0, cone[0], pivot=[0,0,0]) # make the spiral turn
    
    cmds.group(cone_list) # put all the spheres into a group
    cmds.rename("Cone_Spiral") # rename said group
        
def make_Torus_spiral(max_range, change, wl):
    
    torus_list = [] #list of all Toruses
    
    for num in range(max_range):
        torus = cmds.polyTorus() # create the Torus
        torus_list.append(torus[0])
        cmds.move(change/2.0, wl*num, 0, torus[0])  # make the spiral climb
        cmds.rotate(0, num*10, 0, torus[0], pivot=[0,0,0]) # make the spiral turn
    
    cmds.group(torus_list) # put all the spheres into a group
    cmds.rename("Torus_Spiral") # rename said group
    
    
def reset_to_defaults(max_range, change, wl):
    cmds.intSliderGrp(max_range, e=True, value=range_global)
    cmds.intSliderGrp(change, e=True, value=change_global)
    cmds.floatSliderGrp(wl, e=True, value=wl_global)

    
def makeWindow(winName):
    
    if (cmds.window(winName, exists = 1)):
        cmds.deleteUI(winName)

    cmds.window(winName, menuBar=True, resizeToFitChildren=1, width=280, height=100, title=winName)

    cmds.frameLayout(lv = 0);
    cmds.columnLayout(adjustableColumn=True)
    
    
    max_range = cmds.intSliderGrp("Amount", l= "Amount", v=range_global, min=1, max=200, field=True) # int slider group to get the number of many objects
    change = cmds.intSliderGrp("Change", l= "Change", v=change_global, min=-100, max=100, field=True) # int slider group to get how spread out everything is
    wl = cmds.floatSliderGrp("WL", l= "Wave Length", v=wl_global, min=-5, max=5, pre=3, field=True) # float slider group to affect the wave length of the spiral
    
    cmds.separator(height=20,width=400) 

    # Button to Create a Cube Spiral
    cmds.button(l="Create a Cube Spiral", c=lambda x: make_Cube_spiral(cmds.intSliderGrp(max_range, q=True, value=True), cmds.intSliderGrp(change, q=True, value=True), cmds.floatSliderGrp(wl, q=True, value=True)))
     
    cmds.separator(height=20,width=400) 
    
    # Button to Create a Sphere Spiral
    cmds.button(l="Create a Sphere Spiral", c=lambda x: make_Sphere_spiral(cmds.intSliderGrp(max_range, q=True, value=True), cmds.intSliderGrp(change, q=True, value=True), cmds.floatSliderGrp(wl, q=True, value=True)))
    
    cmds.separator(height=20,width=400) 
    
    # Button to Create a Cylinder Spiral
    cmds.button(l="Create a Cylinder Spiral", c=lambda x: make_Cylinder_spiral(cmds.intSliderGrp(max_range, q=True, value=True), cmds.intSliderGrp(change, q=True, value=True), cmds.floatSliderGrp(wl, q=True, value=True)))
    
    cmds.separator(height=20,width=400)
    
    # Button to Create a Cone Spiral
    cmds.button(l="Create a Cone Spiral", c=lambda x: make_Cone_spiral(cmds.intSliderGrp(max_range, q=True, value=True), cmds.intSliderGrp(change, q=True, value=True), cmds.floatSliderGrp(wl, q=True, value=True)))
    
    cmds.separator(height=20,width=400)
    
    # Button to Create a Torus Spiral
    cmds.button(l="Create a Torus Spiral", c=lambda x: make_Torus_spiral(cmds.intSliderGrp(max_range, q=True, value=True), cmds.intSliderGrp(change, q=True, value=True), cmds.floatSliderGrp(wl, q=True, value=True)))
    
    cmds.menu(label="Options") # create an options menu
    cmds.menuItem(label="Reset to Defaults", c=lambda x: reset_to_defaults(max_range, change, wl)) # Menu Item to reset the values to defaults
    cmds.menuItem(label="Delete Selected", c="cmds.delete()")
    cmds.menuItem(label="Close", c=('cmds.deleteUI(\"' + winName + '\", window=True)')) # Menu Item to close the window
    
    cmds.separator(height=20,width=400)



    
    cmds.showWindow(winName)
    
makeWindow("Spirals")