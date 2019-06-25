|   |
|---|


Abstract
========

To emulate a 3D environment, virtual reality headsets require the 3D environment
to be rendered twice, one for each eye, at high resolution and at a high refresh
rate which can be very taxing on currently available consumer computers and
electronics. One way to reduce the workload of rendering a 3D environment and
potentially improve performance of VR applications is to use a rendering
technique named foveated rendering. This rendering technique works on a
principle that “visual resolution decreases rapidly outside the foveal centre”
in human eye (Rossi & Roorda, 2009). This means that eyes only perceive fine
details in the small area at the centre of our field of vision. For a VR
application we can apply same principle to only render a small area of the scene
in full detail while rendering rest of the scene in low detail and resolution.

The area to render in full detail would be determined by the point of gaze of
the user. Therefore, this rendering technique requires user’s gaze to be tracked
in real time using an eye tracker, imbedded in a VR headset. The primary focus
of this project is to develop and prototype a head mounted eye tracking system
to estimate gaze of the user inside a VR headset where there are little to no
light sources.

1.0 Introduction
================

Over the past decade VR has been one of the most trending technologies and as
the need for high resolution and high refresh rate displays grow, more
computational power is required to render 3D environments at such detail.
Foveated rendering can drastically reduce the required computational power to
allow for more detailed virtual environments. Foveated rendering is a rendering
technique which requires an eye gaze tracking device embedded inside a VR
headset to greatly reduce the rendering workload by rendering only the area of
focus in full resolution and rest of the ‘peripheral’ scene in lowest resolution
(“Understanding Foveated Rendering \| Sensics,” 2016). The technique involves
rendering the entire 3D scene in lowest resolution. Then a part of that same
scene, where the gaze is pointing, is rendered in full detail which is then
placed on top of the low detailed scene. A fading blur is then applied around
the edges to this part of scene to seamlessly merge both scenes. This in result
reduces the workload, accelerating graphics computation by a factor of about 5-6
at current HD displays(Guenter, Finch, Drucker, Tan, & Snyder, 2012).

The picture below is taken from (Guenter et al., 2012) which demonstrates the
idea of foveated rendering.

![](media/62bf3b55ca6a187e78a43dad6b962f69.png)

This rendering technique requires an eye tracker inside a VR headset to track
point of gaze of the users which is the focus of this project.

1.1 Project Aim
---------------

The aim of this project is to develop an eye tracking system using a consumer
camera to estimate user’s gaze on a screen and investigate the requirements for
such eye tracking system to be implemented in VR headsets for the purpose of
foveated rendering.

1.2 Project scope 
------------------

This project focuses on the developing eye tracker to be used inside VR headsets
and discuss its effectiveness for one of the use cases foveated rendering,
rather than implementing the foveated rendering itself. This means that in this
project we do not attempt to implement foveated rendering or investigate the
performance gains or its other benefits. As mentioned before, in this project we
attempt to develop a gaze tracker which meets the requirements for it to be used
in VR headsets for foveated rendering.

### 1.2.1 Objectives

Specific aims of this project are

-   Through existing research determine the accuracy and minimum latency
    requirements of the eye tracker for foveated rendering.

-   Develop a Windows application to identify and detect the pupil using a head
    mounted camera.

-   Using same application, determine coordinates of the centre of the pupil and
    map these coordinates onto cursor location.

-   Design and perform tests which can determine latency and accuracy of this
    gaze tracking system.

-   Discuss and evaluate the extent to which accuracy and latency requirements
    for the gaze tracker are met.

### 1.2.2 Deliverables 

The deliverables for this project will be a Windows application which will allow
users to use their gaze to control on screen cursor. The application will also
allow controls for finding pupil as well as calibrating and testing the system.

2.0 Existing work
=================


2.1 Summary
-----------

From the existing research we learn that

1.  There are two types of gaze trackers, remote and head mounted.

2.  There are only few VR headsets that have integrated eye trackers.

3.  Some products are 'add-ons' which can be inserted into existing VR headsets
    and allow users to track their gaze.

4.  PCCR technology is the most common technology used for eye tracking.

5.  Infrared camera and infrared light should be used in order to track gaze in
    dark environment.

6.  The field of vision for human eye can see 135 degrees horizontally and 160
    degrees vertically but the details are perceived only in 5 degrees after
    which the visual acuity drops.

7.  For foveated rendering to be immersive and invisible to users, eye trackers
    need to have a latency of less than 50ms.

These finding define the requirements which gaze tracker needs to meet in order
to allow foveated rendering without breaking immersion. Most importantly, we now
know that the gaze tracker needs to have a latency of less than 50ms and be
accurate with 5 degrees of field of vision. These figures will also be important
for measuring the success of this project.

3.0 Design
==========

The design for this system was mostly governed by the project aim which is to
track user’s gaze point in conditions similar to inside of a VR headset. Overall
the design was similar to existing systems with some variations.

This section will discuss design decisions for both hardware and software as
well as programming environments and programming languages.

3.1 Design decisions and Approach
---------------------------------

Most existing systems such as TOBII Eye Tracking track gaze relative to their
head positions which means they track both head and eyes of the user(“How do
Tobii Eye Trackers work?” 2015). This was not the case for this project as this
eye tracker would always be in a fixed position, so adjusting for head position
is not required. The system also does not need to adjust for distance from the
screen as most of VR headsets have screens at a fixed distance from the eyes.
However, tracking hardware needs to be compact enough to be able to fit inside
of a VR head and be able to function in low light conditions due there being
little to no light inside of a VR headset.

The system is based on image processing approach. A free open source image
processing library Open Computer Vision (OpenCV) is used to record and process
images from a camera.

Although there were various VR headsets available, the system was tested and
developed using a regular computer monitor and a dark environment to simulate
inside of a VR headset. This is because the size of the camera was too big to be
integrated inside a VR headset.

3.2 Camera 
-----------

The choice of camera was determined by the conditions in which the system needs
to function. At first a regular USB ‘snake’ camera was preferred due to its size
being very small. The camera also needs to provide a light source because of
lack of light when a VR headset is worn by the user. Although the camera did
have built in LEDs with adjustable brightness, there was concern of these LEDs
being too close to user’s eye which could possibly damage the eyes.

Due to this reason, an infrared sensitive camera with built in infrared light
source was used. Infrared light being invisible to naked eye meant that only the
camera would be able detect the light from infrared LED, so the system could
work without ‘blinding’ the user.

The infrared camera also provided added benefit of producing high contract
between pupil and rest of the image allowing more accurate recognition of the
pupil.

However, size of this infrared camera was not small enough to fit inside a VR
headset therefore a VR headset was not used in the development process and a
computer monitor screen was used instead.

The minimum focusing distance is also a factor when choosing a camera for such
system because the camera would be real close your eye therefore it needs to be
able focus on really close objects.

The camera used for this project is ELP Infrared Video Camera with a resolution
of 640 by 480 pixels and capture image at frame rate of 24 frames per second.

3.3 OpenCV
----------

OpenCV is an image processing library which, in this system, is used to detect
and recognise user’s pupil. This library “is written natively in C++” (“About -
OpenCV library,” n.d.). The library provides numerous useful functions such as
video capture and image thresholding which are used generously for development
of this system.

OpenCV Version 3.4.0 was used during the development of this system.

3.4 C++ and C++/CLR (Common Language Runtime)
---------------------------------------------

Currently OpenCV only supports “C++, Java, Python and MATLAB interfaces”(“About
- OpenCV library,” n.d.). Python and MATLAB were not used due not having enough
experience with these languages and using a familiar programming language can
minimise the time for development of this system. Between Java and C++, C++ was
chosen for development of this system as it’s the language which the OpenCV is
natively written in and C++ also supports Visual Studio which provides latest
tools for debugging and version control.

The system was intended to be a console application; however, it was soon
realised that a graphical user interface is necessary to allow the application
to be flexible.

Therefore, I decided to use C++/CLR to import existing work to an interactive
user interface. Although C++/CLR provided more than enough tools to make a GUI,
it did not work well to integrate with some of the functions from OpenCV as we
shall see.

3.5 Platforms
-------------

There are several platforms that support VR technology such Android, iOS and
Windows. This project is aimed at Windows as it is widely adapted in consumer as
well educational markets as surveyed by around 81% of the operating system
worldwide are Windows.

The design and algorithms of this system are easily adaptable to other platforms
and certainly other programming languages though for this project the
application produced was made to be only Windows compatible.

3.8 Main program
----------------

The main program starts with taking a frame as input from the camera and loops
until the program is ended or the camera has been changed. The user is then
required to perform calibration before eye tracking can start. Once user has
calibrated the screen the user can start tracking. The program will loop until
user prompts to stop.

During calibration process user is presented with nine points on the edges and
centre of the screen. These points are numbered from 1 to 9 and user is required
to follow them in order. For every point the coordinates of the pupil are
stored. The calibration process gives us boundaries of the pupil movement
relative the monitor’s screen.

The calibration step is very important for this system to function properly.
Generally, such systems by nature require calibration to acquire a point of
reference in the exterior environment which will be different for individual
users.

4.0 Development
===============

This section describes and discusses the development and implementation process
of the system and challenges or problems encountered during the development. It
also discusses any changes made to algorithm and their effect on the overall
system.

4.1 Main application
--------------------

The main application starts with a simple GUI developed using C++-CLR
environment. The GUI form contains buttons and controls necessary to use the
system. Main screen also provides a guide and instructions to use the system. In
the system the main ‘form’ acts as the hub to which other classes can
communicate to; in other words, it is the main class which contains and uses
other class objects.

4.2 Camera input
----------------

At the main screen of the program user decides which camera to open, this is
because computers can have more than one camera installed. A background worker
thread is created which runs independent of program’s main thread; this
background worker runs a function in loop. That function is given a camera id
which is the camera id selected by the user and it is responsible for reading a
camera frame from the camera until the program is ended. A function from OpenCV
library is then used to attempt to open selected camera inside ‘PupilDetect’
object using function

VideoCapture capture(cameraId)

Similarly, once the camera is opened, a new frame is captures using OpenCV
function

capture.read(image)

Once we have the frame from the camera we can process it to find the region
where an eye is found.

4.3 Finding Eye
---------------

Finding an eye narrows down the region where a pupil could be located which
eliminates any noise or artefact which could be recognised as pupils affecting
the reliability of the system. To find the eye, a haar cascade classifier
*haarcascade_eye.xml* was used which is included in OpenCV library. This cascade
was chosen as this system only deals with one eye and does not deal with changes
head movement or two eyes.

Using OpenCV functions, haar cascades are loaded which detect eyes and store
them in a vector of rectangles named ‘eye’.

CascadeClassifier eyeCascade("haarcascade_eye.xml");

eyeCascade.detectMultiScale(currentFrame, eye, 1.1,…

If an eye is found it will have a surrounded rectangle within which we will look
for a pupil.

However, the function CascadeClassifier did not load the cascade classifier and
returned compiler exception (System.Runtime.InteropServices.SEHException) which
even after numerous attempt and work arounds was not fixed. Eventually the
system was developed without the use of these functions and without finding the
eye in the frame.

4.4 Finding Pupil
-----------------

Not being able to find the region of the eye meant that the pupil was to be
searched in the whole frame. To find the pupil in the camera frame a threshold
is applied. To apply the threshold the frame first needs to be converted into
black and white which was done by using OpenCV’s function cvtColor. To minimise
the noise GaussianBlur is also applied to the frame. Applying threshold to the
frame leaves the darkest area in the frame. This is where an infrared camera
produces best results as it gives pupil a high contrast than the rest of the
frame and eliminates most of the shadows.

The function findContours is used to find all the ‘edges’ in the processed frame
and then are stored into a vector. The problem with this approach is that there
can be multiple dark spots in a frame which can affect the accuracy of the
cursor movements when using the system. Extracting the region of eye in framed
would have minimised these dark spots. Since, it was not possible to find region
where eye is located, another approach to minimise the false detection of pupil
was used. For this approach to work, the area of each minimum enclosing contour
needs to be calculated. The area of each minimum enclosing contour can be found
using contourArea function provided by OpenCV library. Users are then able to
adjust the minimum and maximum area for each contour to filter out any noise or
unwanted areas which are too big to be logically the size of a pupil in the
frame. Adjusting the threshold intensity can also help reduce noise in the
processed frame. Image below shows a screenshot of the control that are
accessible to the users.

![](media/2f29eebee54b20b3a3a2c95af36e78a4.png)

After a pupil has been detected its contour data is used fit an ellipse using
fitEllipse function.

One image below shows the contours of the found pupil while other shows an
ellipse fitted using those contour points

![](media/09e3d94490f219f00f353278bc809240.png)

![](media/a6f2c41212a707cc1f0cec7732f62055.png)

It is apparent in first image that even though a pupil has been found, a glint
from infrared light source is preventing the pupil to be detected fully where as
an ellipse is overall a good fit covering most of the area where the pupil is
located. The minEnclosingCircle is then used to find the centre of the pupil.
The centre of the pupil are the X and Y coordinates of the pupil relative to the
camera frame.

A function getPupilPosition can then return these coordinates to be used by
other classes.

4.5 Calibration 
----------------

Calibration process is very important for this system to work. Users are
required to run the calibration process every time the program is opened. The
program contains a calibration form which runs in full screen and has nine red
circles around the edges which are numbered 1 to 9. Users are required to look
at each circle and press ENTER key once for every circle. When a user presses
ENTER key the coordinates of the pupil are stored in an array of length 9. Once
users have done the calibration they can exit this form using provided exit
button. These nine coordinates determine the boundaries of the screen and
maximum and minimum values of where a pupil can reach. Users can also
recalibrate if the position of the camera has been changed or the distance of
the users from the screen is changed.

Picture below is a screenshot of the calibration screen.

![](media/292502c68c6fedd4867b3ce9f23e2b59.png)

Diagram below demonstrates calibration process.

![](media/555d88f3816b5b9b5fe2f71ab82084eb.png)

>   ­

4.6 Tracking
------------

Tracking was the hardest part of this project and it was challenge to map
coordinates of the eye onto the screen. The algorithm to translate pupil
coordinates into cursor positions is

$$
X_{c} = \left( X_{p} - C_{x} \right)*\left( \frac{S_{w}}{C_{x}} \right)
$$

$$
Y_{c} = \left( Y_{p} - C_{y} \right)*\left( \frac{S_{h}}{C_{y}} \right)
$$

where $$X_{c}$$ and $$Y_{c}$$ are the cursor coordinates to be calculated,
$$X_{p}$$ and $$Y_{p}$$ are the current pupil coordinates, $$C_{x}$$ and
$$C_{y}$$ constants are the coordinates of the calibration points and $$S_{w}$$
and $$S_{h}$$ are the width and height of the monitor screen. The division
between $$S_{w}$$ and $$C_{x}$$ is the size factor by which the X coordinates of
the pupil will be multiplied. The multiplying factor for Y coordinates is also
calculated in the same manner.

Diagram below shows how the movement of the eyeball would be translated into
cursor positions.

However, due to the topography and curvature of the eye ball, the relationship
between points on the screen and position of the pupil was not linear.

Diagram below demonstrates the expected coordinates versus actual coordinates of
pupil positions acquired during calibration.

This meant that the multiplying factor would vary depending on the location of
the pupil. Due to this, the multiplying factor was calculated separately in one
of the four quadrants given by the array of calibration points. By determining
which quadrant the pupil is detected in, i.e. top left, bottom left, top right
and bottom right, the correct calibration point $$C_{x}$$ or $$C_{y}$$ is used
to calculate the multiplying factor. Once we have the new calculated coordinates
the function moveCursor is called to move the onscreen cursor.

5.0 Testing 
============

The system was developed and tested on a Windows machine with following
specifications.

CPU: Intel(R) Core(TM) i7-7700HQ CPU \@ 2.80GHz (8 CPUs), \~2.8GHz

Memory: 8192 MB

Windows 10 Home 64 bit

There are two main areas in which this system is needed to be tested which are
accuracy and the latency which, during background research, were found to be
most important factors for foveated rendering to be immersive and effective. The
system would also be evaluated in different levels of luminosity such light and
dark environments for which the camera would be inside a box to simulate a VR
headset.

5.1 Testing Methodology
-----------------------

The test methodology for this system is a adapted version of (“Tobii ®
Technology Accuracy and precision test method for remote eye trackers,” 2011).
The article explores various techniques for testing remote eye trackers however;
these methods can be adapted for evaluation of this system. Data from all the
test and feedback forms is stored in project’s directory as .txt files.

5.2 Measuring accuracy
----------------------

One of the methods for measuring accuracy in this paper was to prompt user to
move the cursor every two seconds at a specific location using their gaze as
input method. The program generates a random location within the screen and
places a red circle at that location. Users are then required to move the cursor
at that location. The paper also mentions to only take measurements when the
time interval is between 800ms and 1800ms out those 2 seconds; this is “to make
certain that the participant has time to move his/her gaze to the correct point
on the screen”. Once the time has elapsed the distance from pointer location to
the location of the object is calculated and it is used to calculate the
percentage error i.e. smaller distance would mean higher accuracy and vice
versa.

In that paper the distance between the onscreen object and cursor position was
calculated by

$$
D = \sqrt{{{(X}_{t} - X_{c})}^{2} + {{(Y}_{t} - Y_{c})}^{2}}
$$

where $$X_{t}$$ and $$Y_{t}$$ are coordinates of the target and $$X_{c}$$ and
$$Y_{c}$$ are coordinates of the cursor. This equation is essentially a
Pythagoras equation. For this project same equation will be used to determine
the accuracy of the system in pixels.

These tests were performed on five individuals and their results can be found in
Appendix C.

5.3 Measuring latency
---------------------

According to (Albert et al., 2017) optimum accepted latency for such systems is
between 0 to 40ms which will be an indicator of success of this system. The
article (“Timing Guide for Tobii Eye Trackers and Eye Tracking Software,” 2010)
defines the latency of the tracking system as the “amount of time taken to find
the centre of the pupil as well as amount of time taken to calculate new cursor
position”. The graph below is taken from (“The parameters of eye movement,”
n.d.) which shows the time taken for eye to rotate by certain degrees. It shows
that to move the eye by 5 degrees would take about 30ms therefore the latency of
this system should also be in that range.

![ampdur.gif (5712 bytes)](media/bbd45af753f861ab2fcf31fd4a9396bb.gif)

To test the latency of this system, the average sum of execution times of the
functions that find the pupil and move the cursor will be calculated.


6.0 Conclusion 
===============

The aim of this project was to develop a system for tracking user’s gaze inside
a virtual reality headset which defined the requirements for this system to be
considered a success. The results clearly show that system is not reliable or
accurate enough to be used in virtual reality headsets for foveated rendering
and a better approach is can be used map pupil centre to gaze point. The system
can accurately detect pupil almost always but this is dependent on the image
resolution and number of dark spots in that image. The accuracy of the system is
also within the radius of roughly 150 if calibrated correctly. But this is
subjective as the system does not work reliably. The latency of the system was
also not a true representation of the system as the accuracy of these
measurements were limited by the camera used.

Despite its problems, the project overall showed that there is more research
needs to be done to develop fast, accurate and low latency eye gaze trackers in
order to be used inside VR headsets for use cases such as foveated rendering.
The project also highlighted the key hardware requirements such as infrared
camera for such system to work inside VR headsets and highlighted algorithms and
existing work for area of eye tracking and point of gaze calculation.
