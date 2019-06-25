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

This chapter will discuss the existing work for both foveated rendering and eye
tracking which will help us to clarify the requirements of the gaze tracker for
foveated rendering. These requirements will provide a basis for measuring
success of the project as well as the deliverables.

2.1 Foveated Rendering
----------------------

Despite the promised performance boost there are not many implementations of
foveated rendering technique in real life applications. For this technique to be
practical in VR applications the system must have a reliable and portable eye
tracking system which itself is a technology that is still early “embryonic”
stages of research(Gao, Yin, Cheng, & Feng, 2012).

### 2.1.1 Microsoft 

The research “Foveated 3D Graphics” (Guenter et al., 2012) by Microsoft involves
rendering three eccentricity layers denoted as inner/foveal layer, middle layer,
and outer layer. Each layer is progressively smaller in angular size and
resolution with the inner layer being the smallest and rendered in
highest/native resolution and level of detail while middle and outer layers are
rendered at decreasing resolution and level of detail. All of three layers are
then composited into one scene. The paper states that eyes see 135° vertically
and 160° horizontally but only detect the fine details in 5° of our field of
vision implying that performance gain increases with the size of the display.
The paper also states the problem of latency between a user shifting the gaze
point and system loading the higher resolution layer at the new gaze point.
Having too much latency can cause the “popping” effect of the inner layer into
the outer layer diminishing the effect of seamlessly blending layers. The system
latency was reduced by using 120Hz high refresh monitor of instead of 60Hz
monitor as well as a high speed eye tracker Tobii TX300 with 300Hz update rate
with a “worst case latency of 10ms”.

### 2.1.2 NVIDIA 

While Microsoft’s research focused on using foveated rendering for monitor
displays NVIDIA’s research is more focused on virtual reality headsets also
known as head mounted display (HMD) with an integrated eye tracker. This
research finds that our peripheral vision is best at sensing changes in motion,
colour and contrast(Patney et al., 2016). In another paper (Albert, Patney,
Luebke, & Kim, 2017) at NVIDIA looked at latency requirements for such system as
well conducted experiments on different techniques to evaluate perceptual impact
of adding latency to the system and determine the “relationship between
foveation technique, fovea size and amount of foveation that can be tolerated”.
The paper states that adding latency on 80ms or more negatively affected all the
techniques while no significant difference was found for lower added latencies
i.e. 0, 10, 20, and 40ms suggesting that there is some amount of acceptable
latency where artefacts are not detected by user while moving the eyes and only
artefacts detected would be in the periphery field of vision. These values are
important for this project because these values can be used as a baseline to
compare the latency of this system.

### 2.1.3 Google

The research blog by (Behnam, Bastani, Eric, 2017) discusses the two techniques
to reduce artefacts while foveatly rendering environments for virtual or mixed
reality. The artefacts are introduced by not having anti-aliasing in low visual
acuity regions which are rendered at partial or lower resolutions. These
artefacts become noticeable and break the immersion when there are quick
movements or fast animations. The two different methods to reduce these
artefacts that this blog presents are known as Phased Aligned and Conformal
foveated rendering.

For phase aligned foveated rendering, the frustums (portions of a solid shape)
are aligned rotationally to the world rather than the current head rotation.
Therefore, rather than moving the pixel grid matrix across virtual scene, the
frustums stay fixed in one direction i.e. south, north, east or west and rotate
when the head is rotated.

The blog states that phase aligned rendering is more expensive on computing
resources than other techniques, but net savings can be achieved by “pushing
foveation to more aggressive levels that would otherwise have yielded too many
artefacts”.

Conformal foveated rendering works similarly to traditional foveated rendering
but instead of rendering a frame in layers with increasing resolutions, i.e. a
low resolution layer for periphery vision and high resolution layer for fovea,
it takes a frame and ‘crops’ the area of high acuity; only the data for cropped
part of the frame and the low resolution frame are passed, reducing the number
of bits needed to transfer. The idea is that in traditional foveated rendering,
the buffer will need 3 full layers, each for different resolution, whereas for
conformal foveated rendering it only needs a low resolution frame and small
cropped section of high resolution frame.

The image below is taken from that blog which shows the frame which the user
will perceive and actual contents that are transferred. Although not to scale,
the image on the left is what the user will perceive and image on the right is
what is actually processed.

![](media/d9497d2639d5a37dab425b9a91dd9171.png)

Conformal foveation reduces the bandwidth for foveation rendering which in
result reduces cost of computing power though it is not as good as phase aligned
rendering for reducing artefacts.

2.2 Eye tracking
----------------

### 2.2.1 TOBII Eye tracking

Tobii eye tracking is a manufacturer and developer of eye and head tracking
devices such as TOBII Eyetracker 4C. These eye trackers are advanced version of
traditional Pupil Centre Corneal Reflection (PCCR) eye tracking technology(Tobbi
Technology, 2010). This technology uses a light source to illuminate eyes,
causing a reflection in cornea of the eye. Using multiple light sources will
create a pattern in the reflection which can be used to calculate the vector
between the centre of the pupil and location of the reflection/glint. Using this
vector and building a 3D model of geometrical features of the eye, the gaze
point can be estimated.

### 2.2.2 Pupil Labs

Pupil labs is a company which has designed and developed eye tracking glasses
that track point of gaze in open space as well as in virtual environments
(Kassner & Patera, 2012). They have also developed an add-on, pictured on the
next page, which can be inserted into VR headsets (Oculus Rift, HTC Vive or
Microsoft HoloLens) to track gaze point of the user.

![HTC Vive Eye Tracking Add-On](media/76eb40e07a7d548389d3ac45e9e21b31.png)

The eye tracker that is built into this add-on has latency of 4.5ms, has IR LEDs
to illuminate the scene and uses high speed 120hz cameras to capture the pupil
(“Pupil Labs - VR AR,” n.d.). This add-on is the closest finished product to the
topic of this project.

### 2.2.3 Research papers

Eye tracking or gaze tracking is a well-researched topic involving various
methods and techniques which can generalised into two categories, remote (head
position based) eye trackers and head mounted eye trackers. Remote eye trackers
usually track the gaze point in 3D space by compensating for head movement and
head orientation. These are also known as 3D Gaze Trackers and are useful when
the system needs to be non-intrusive and be adaptable to different users
eliminating the need for calibration or special equipment to be worn by users.
Whereas traditional head mounted gaze trackers require users to wear special
equipment which (Baluja & Pomerleau, 1994) describe as “cumbersome”. (Kar,
Anuradha ,Corcoran, 2017) discuss and evaluate the performance and effectiveness
of various gaze estimation methods in consumer environments. Their primary focus
was on remote eye trackers and investigated the “consistency and accuracy of
such system while operating under real world conditions”.

Most gaze trackers use Pupil Centre Corneal Reflection (PCCR) eye tracking
technology to detect the pattern formed by glints from infrared light source and
use them as a reference point to calculate the pupil location. This type of
system requires calibration which produces some constant values to be used for
eye to screen mapping.

For this project, the gaze tracker can be called as head mounted since it is
intended to be integrated inside a VR headset which will be worn by users.

2.3 Summary
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

3.6 System Overview
-------------------

The diagram below shows overview of system structure.

3.7 Algorithm Overview
----------------------

There are two main algorithms which make up this system, finding the pupil and
calculating the gaze point. A simplified overview of each algorithm is below.

There are two main pipelines in the program, first pipeline is responsible for
getting a new frame from the camera and processing it to locate pupil and
another is mapping gaze point and setting cursor position on the screen.

A frame is captured from the infrared camera which is then used to extract the
eye region from the frame using haar-cascades. Haar cascades are classifiers
which are trained through machine learning to detect objects for which they are
trained for. We will be using these classifiers to detect the eye because they
are already provided by OpenCV library and they are very effective at detecting
objects.

The detected region is then processed using desired parameters such as threshold
and area (more on this in Development section 4.4) to detect pupil. Once the
pupil has been detected the centre of the pupil is determined. The centre of
this pupil has coordinates which are relative to the camera frame.

These coordinates are then used to map coordinates of the camera frame on
coordinates of the screen using data acquired during calibration process. The
cursor is then moved to these coordinates respectively.

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

6.0 Evaluation of results
=========================

Overall, the system meets some of the requirements that define its success. The
testing results show that system can function as a head mounted device in light
or dark environments. The accuracy of the system, however, has a large error
margin and often produces unreliable results.

6.1 Accuracy in high luminosity
-------------------------------

Table below shows the results of a user’s attempt to move cursor at 10
predetermined locations where the circle would be.

| Mouse X | Target X | Mouse Y | Target Y | Distance (pixels) |
|---------|----------|---------|----------|-------------------|
| 312     | 240      | 114     | 105      | 72                |
| 84      | 41       | 138     | 107      | 53                |
| 552     | 574      | 450     | 580      | 131               |
| 1860    | 1889     | 600     | 604      | 29                |
| 1919    | 1878     | 288     | 198      | 98                |
| 108     | 82       | 642     | 704      | 67                |
| 1820    | 1865     | 144     | 65       | 90                |
| 120     | 241      | 624     | 627      | 121               |
| 456     | 361      | 474     | 491      | 96                |
| 1116    | 1075     | 144     | 62       | 91                |

The results above show that the eye tracker can be accurate within the radius of
150 pixels. Although these results can be regarded as fairly accurate, they are
far from being precise. Which is not an issue since the eye tracker for this
system does not need to be precise. However, the system also turned out to
extremely unreliable because sometimes the pupil is not detected which sets the
mouse pointer location to 0 producing large error. In addition, sometimes other
parts of the image are falsely detected as pupil which also make the mouse
pointer move to random positions.

The table below shows one example where distance from target is quite big.

| Mouse X | Target X | Mouse Y | Target Y | Distance (pixels) |
|---------|----------|---------|----------|-------------------|
| 392     | 240      | 144     | 105      | 156               |
| 42      | 41       | 180     | 107      | 73                |
| 560     | 574      | 504     | 580      | 77                |
| 1919    | 1889     | 0       | 604      | 604               |
| 1800    | 1878     | 272     | 198      | 107               |
| 126     | 82       | 702     | 704      | 44                |
| 1919    | 1865     | 0       | 65       | 84                |
| 588     | 241      | 594     | 627      | 348               |
| 490     | 361      | 486     | 491      | 129               |
| 0       | 1075     | 0       | 62       | 1076              |

There was also an issue of mouse jittering in one place i.e. moving rapidly in
one area due to slightest variations in pupil centre. To reduce number of these
errors, average readings of the cursor location can be taken which will also
eliminate anomaly results from the accuracy calculations. However, doing so
would increase the latency as system would need to wait to gather values for
taking average. False matches for the pupil can also be reducing by tweaking the
threshold intensity and or defining a minimum and maximum area of the ellipse to
be regarded as pupil. The errors were also affected by accidently misplacing the
camera in different position due it not being in a firm place relative to the
screen.

The distance of camera from eye was found to best at 5cm in order to detect
pupil reliable, this distance is mainly dependant on the near focusing
capabilities of the cameras lose focus when they get closer to objects.

6.2 Accuracy in low luminosity
------------------------------

Similar results were observed in low light conditions. Table below is one of the
examples.

| Mouse X | Target X | Mouse Y | Target Y | Distance (pixels) |
|---------|----------|---------|----------|-------------------|
| 320     | 240      | 110     | 150      | 80                |
| 104     | 41       | 90      | 107      | 65                |
| 576     | 574      | 580     | 580      | 2                 |
| 1919    | 1889     | 570     | 604      | 45                |
| 1864    | 1878     | 220     | 198      | 26                |
| 192     | 82       | 670     | 704      | 115               |
| 1781    | 1865     | 76      | 65       | 84                |
| 392     | 241      | 630     | 627      | 151               |
| 416     | 361      | 460     | 491      | 63                |
| 1096    | 1075     | 200     | 62       | 139               |

These results show that there is little to no effect on the accuracy of the
system in different levels of luminosity. This is expected because an infrared
camera and infrared LED is used to illuminate the scene.

6.3 Latency of the system
-------------------------

While calculating latencies the execution times of actual functions was between
3ms to 5ms however, this is not an accurate representation of the actual latency
of the system. There are two main factors in this system which give it an
average latency of 80ms. One of the factors is the refresh rate of the camera
which is 30fps and it significantly affects the overall system latency, this
latency can be reduced by using a high refresh rate camera. Another factor which
contributes to the latency of the system is the OpenCV’s function VideoCapture
which keeps image frames in buffer until they are processed.

6.4 Design and Implementation
-----------------------------

Although the design of the system is functional, it is very limited. The design,
as it is now, can only be used to move the cursor but in a real world use it
would need to be used as an independent method of Human Computer Interaction
(HCI). This means that design needs to be portable and flexible so that it
allows integration of other systems or environments which are necessary for this
system to have a use case.

The implementation of this system was Windows specific as it is extremely
reliant on libraries and functions that are compatible with Windows only which
is not practical for the design of the system.

6.5 Testing methods
-------------------

The method of testing the accuracy was easy to understand, simple to follow and
produced useful results. Testing latency however, turned out to be very
difficult and results produced will vary depending on processing speed of a
computer and resolution of image from the camera, resolution of the display and
frame rates of camera as well as the display. The testing was also not a direct
representation of the usage of this system in real world as during the testing
the system was not integrated in a VR headset nor it was tested for foveated
rendering. The number of tests done was also not adequate; more tests on
different platforms, different machines and different people need to be carried
out to produce valid and reliable results.

The performance of the system, in terms of usage of computing resources such as
CPU and memory, was also not tested.

6.6 Usability 
--------------

The goal of the usability testing was to determine whether the user interface,
which implements the gaze tracking system, is functional and provides enough
help and support to use the system. Users were given five tasks to perform and,
in the end, they were asked to give feedback in terms of a questionnaire and
rating out of up to 5, the feedback is then saved in a text file. The task list
and questionnaire can be found in Appendix D.

The questions in that questionnaire are about ease of use, quality of
instructions, reliability of the application for detecting pupil, reliability of
the application to accurately move the cursor and appropriate way of displaying
information or error messages.

The results from this feedback showed that most users agreed on the ease of use
of the system and display of relevant information, however, the calibration form
seemed to be problematic as some users would press the ENTER key randomly when
they didn’t mean to which resulted in inaccurate calibration data and required
users to recalibrate. This can be improved by allowing users to be able to
discard or delete the last calibration point rather than starting the
calibration process all over again.

7.0 Critical review
===================

The inspiration for this project came from the trend of virtual reality and
augmented reality technologies, such Microsoft HoloLens and HTC Vive, and
discussions about hardware that could support the VR applications. The
deliverable achieves most of the objectives as we can detect pupil, track the
pupil and control the cursor with gaze as well as we are able to deduce
measurements for accuracy and latency. Although the deliverable provides the
features and functionality for gaze estimation, it is not effective enough to be
used for foveated rendering.

7.1 Pupil detection approach
----------------------------

The method of pupil is not very reliable as searches for dark and round spots in
a frame rather than actually defining a criterion to match pupil. This means
that if a spot in the frame is darker than the pupil then the pupil definitely
would not be detected accurately. This problem can be solved by using other
techniques which are more complex and advanced but reliable. One of these
techniques is to use machine learning to train the neural network to recognise
the pupil as discussed by (George & Routray, 2016). They use a Convolutional
Neural Network based gaze direction classifier which adapts to position of the
eye in the scene and outperforms most traditional algorithms for eye and pupil
localisation.

Another commonly used approach which could be used in this system for accurately
determining point of gaze is to use glint from a light sources and corner of the
eye to calculate a vector which is then used to calculate scaling factor. (Li &
Parkhurst, 2005) discuss a hybrid feature based and model based algorithm
“starburst” which is more accurate for detecting pupil than the ones that are
only feature based. The algorithm starts with guessing best point for pupil
centre and from that point it ‘casts’ a ray of points radially which continue if
the intensity at that point is similar to the first guessed point, if it isn’t
the ray is halted. Once all the rays are halted an ellipse fitting algorithm is
applied as an indication of the pupil location. Rays that were only halted at
the edges of the screen are discarded leaving a set of features in the frame.
Out of those features the model based algorithm is used to determine the feature
that is a pupil. Pictures below are taken from that paper which show the
implementation of this approach. Green crosses represent the end of a ray.

![](media/ab75284edd147067b8c73645c2faf33a.png)

7.2 Choosing camera
-------------------

Not having the right camera was a real setback for this project; as I initially
used a regular webcam which failed to detect the pupil most of the times and the
eye also needed to be wide open for pupil to be detected. This issue was solved
by using an infrared camera which provided a much better contrast between pupil
and rest of the image. Arguably, the regular webcam could have worked perfectly
if the technique for finding the pupil was appropriate though it was easier to
use webcam with infrared camera than rewriting the application to make it work
with regular webcam. Infrared camera had the added benefit of being to record in
the dark without creating visible light, which solved the problem of making the
system work in the dark. The camera was also replaced few times because of cheap
hardware quality or missing functionality which also resulted in delay of at
least a week.

7.3 Limitations
---------------

As this system is to be a prototype only there were some limitations to it. To
keep the system simple the gaze was estimated for one eye only and used only one
camera. Using one camera means that there will be no depth perception which can
affect the immersion in VR environment though this will not affect the foveated
rendering. Although I had the access to some VR headsets, the camera for eye
tracker was too big to fit inside one. The camera used also had a maximum
resolution of 640 by 480 pixels which could be a limiting factor for the
accuracy of the system. The camera also had an update or refresh rate of 24
frames per second, this meant that the application would be waiting for a new
frame until the camera captures a new frame. The system was also tested on a
single computer and a display resolution of 1920 by 1080 with refresh rate of
60hz; the results for accuracy and latency will vary depending on processing
power of the computer and display refresh rate and resolution.

The camera that was used also too heavy to be head mounted therefore users were
required to hold it in the hand or mount the camera on a stand and keep the head
still. However, it is very difficult for users to not move the head relative to
the camera as it is naturally almost impossible. Using a head rest minimised the
head movement but there were still slight movements which affect the accuracy of
the system. The system was also not tested for different scenarios such users
wearing glasses due to time constraints and availability of the users.

7.4 Ethical issues
------------------

One major issue with this system is the privacy in a sense that user may not be
comfortable with their eye being recorded. Other than foveated rendering, eye
trackers can be in other industries such as marketing which can provide
advertisements depending on where the users are looking at. Other industries
such as automotive can implement the eye trackers to judge users if they in good
condition to drive for which users can also be uncomfortable as it is a privacy
concern.

7.5 Future considerations
-------------------------

The system in its current state has a lot of room for improvement especially in
the design and main tracking algorithm. If this project was to be done again I
would use a programming environment/IDE such C\# with .NET or QT Creator, which
have native support for making GUI applications. Using C++/CLR was very
problematic as the final application is partly ‘Windows::subsystem” and partly
Win32 (OpenCV). Due to this I had to have ‘a OpenCV window’ named as “Panel”
left open for the application to work. C++/CLR environment also, to my
understanding, cannot display images of type ‘Mat’ and they have to be converted
into ‘Bitmap’ to be viewed in ‘pictureBox’. Additionally, there were no
functions available in standard libraries in C++/CLR or OpenCV that could
convert Mat image into Bitmap image and work around for displaying a Mat image
in a pictureBox was very inefficient.

Testing is also another area which could be given more time and thought in the
future. Testing for such systems needs to be carried out in variety of likely
user scenarios and user profiles. Through testing we would be able to determine
ideal measurements for conditions such screen distance, camera distance from the
eye, angle for the placement of camera to eye, threshold intensity and different
levels of luminosity. We would also need to test for cameras with varied refresh
rate, VR displays with high refresh rate and field of view provided by those VR
headsets. By measuring accuracy and latency we can also determine the optimum
sharpness and resolution of the camera to avoid unnecessary processing of large
image files and sacrificing performance by increasing bandwidth.

To test the true effectiveness of the system, it needs to be tested within
virtual reality environment where it is intended to be used. However,
determining the performance benefits would be a research topic on its own which
is not in the scope of this project though there is plenty of other research
work for this topic by global companies such as Google(Behnam, Bastani, Eric,
2017), Microsoft (Guenter et al., 2012) and NVIDIA (Patney et al., 2016).

Another area this system can be improved is to have a calibration free eye
tracking system which can automatically calculate variables which define the
scaling factor. Such solution would be user friendly and can be integrated with
machine learning and improves the accuracy over time by predicting positions of
the pupil.

This type of system would also greatly benefit from parallel computing because
most of the work is done with image processing for which the GPU computing
provides the best performance depending on type of algorithms used.

8.0 Conclusion 
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

9.0 References
==============

About - OpenCV library. (n.d.). Retrieved April 1, 2018, from
https://opencv.org/about.html

Albert, R., Patney, A., Luebke, D., & Kim, J. (2017). Latency Requirements for
Foveated Rendering in Virtual Reality. *ACM Trans. Appl. Percept. Article*,
*14*(13). https://doi.org/10.1145/3127589

Baluja, S., & Pomerleau, D. (1994). Non-Intrusive Gaze Tracking Using Artificial
Neural Networks. In J. D. Cowan, G. Tesauro, & J. Alspector (Eds.), *Advances in
Neural Information Processing Systems 6* (pp. 753–760). Morgan-Kaufmann.
Retrieved from
http://papers.nips.cc/paper/863-non-intrusive-gaze-tracking-using-artificial-neural-networks.pdf

Behnam, Bastani, Eric, T. (2017). Research Blog: Introducing a New Foveation
Pipeline for Virtual/Mixed Reality. Retrieved from
https://research.googleblog.com/2017/12/introducing-new-foveation-pipeline-for.html

Gao, D., Yin, G., Cheng, W., & Feng, X. (2012). Non-Invasive Eye Tracking
Technology Based on Corneal Reflex. *Procedia Engineering*, *29*, 3608–3612.
https://doi.org/10.1016/j.proeng.2012.01.539

George, A., & Routray, A. (2016). Real-time Eye Gaze Direction Classification
Using Convolutional Neural Network. Retrieved from
https://arxiv.org/pdf/1605.05258.pdf

Guenter, B., Finch, M., Drucker, S., Tan, D., & Snyder, J. (2012, November 20).
Foveated 3D Graphics. Retrieved from
https://www.microsoft.com/en-us/research/publication/foveated-3d-graphics/?from=http%3A%2F%2Fresearch.microsoft.com%2Fpubs%2F176610%2Ffoveated_final15.pdf

How do Tobii Eye Trackers work? - Learn more with Tobii Pro. (2015). Retrieved
from
https://www.tobiipro.com/learn-and-support/learn/eye-tracking-essentials/how-do-tobii-eye-trackers-work/

Kar, Anuradha ,Corcoran, P. (2017). A Review and Analysis of Eye-Gaze Estimation
Systems, Algorithms and Performance Evaluation Methods in Consumer Platforms,
25. https://doi.org/10.1109/ACCESS.2017.2735633

Kassner, M. P., & Patera, W. R. (2012). *PUPIL: Constructing the Space of Visual
Attention*. Massachusetts Institute of Technology. Retrieved from
http://hdl.handle.net/1721.1/72626

Li, D., & Parkhurst, D. J. (2005). Starburst: A robust algorithm for video-based
eye tracking. Retrieved from
https://pdfs.semanticscholar.org/1b44/723236a67389c3adaad848f4f7ae9d70b8ea.pdf

Patney, A., Kim, J., Salvi, M., Kaplanyan, A., Wyman, C., Benty, N., … Luebke,
D. (2016). Perceptually-Based Foveated Virtual Reality.
https://doi.org/10.1145/9999997.9999999

Pupil Labs - VR AR. (n.d.). Retrieved April 8, 2018, from
https://pupil-labs.com/vr-ar/

Rossi, E. A., & Roorda, A. (2009). The relationship between visual resolution
and cone spacing in the human fovea. *Nature Neuroscience*, *13*, 156. Retrieved
from http://dx.doi.org/10.1038/nn.2465

The parameters of eye movement. (n.d.). Retrieved April 5, 2018, from
https://www.liverpool.ac.uk/\~pcknox/teaching/Eymovs/params.htm

Timing Guide for Tobii Eye Trackers and Eye Tracking Software. (2010). *Tobii
Technology*. Retrieved from
https://www.tobiipro.com/siteassets/tobii-pro/learn-and-support/design/eye-tracker-timing-performance/tobii-eye-tracking-timing.pdf/?v=1.0

Tobii ® Technology Accuracy and precision test method for remote eye trackers.
(2011). Retrieved from
https://www.tobiipro.com/siteassets/tobii-pro/accuracy-and-precision-tests/tobii-accuracy-and-precisiontest-method-version-2-1-1.pdf

Understanding Foveated Rendering \| Sensics. (2016). Retrieved March 29, 2018,
from http://sensics.com/understanding-foveated-rendering/

10.0 Appendices
===============

Cursor accuracy test for user 1

| Mouse X | Target X | Mouse Y | Target Y | Distance (pixels) |
|---------|----------|---------|----------|-------------------|
| 336     | 240      | 168     | 105      | 114               |
| 84      | 41       | 192     | 107      | 95                |
| 588     | 574      | 672     | 580      | 93                |
| 1919    | 1889     | 0       | 604      | 604               |
| 1919    | 1878     | 0       | 198      | 202               |
| 252     | 82       | 744     | 704      | 174               |
| 1919    | 1865     | 0       | 65       | 84                |
| 378     | 241      | 624     | 627      | 137               |
| 490     | 361      | 600     | 491      | 168               |
| 1000    | 1075     | 132     | 62       | 102               |

Cursor accuracy test for user 2

| Mouse X | Target X | Mouse Y | Target Y | Distance (pixels) |
|---------|----------|---------|----------|-------------------|
| 288     | 240      | 176     | 105      | 85                |
| 156     | 41       | 66      | 107      | 122               |
| 540     | 574      | 680     | 580      | 105               |
| 1919    | 1889     | 0       | 604      | 604               |
| 730     | 1878     | 0       | 198      | 1164              |
| 348     | 82       | 704     | 704      | 266               |
| 1890    | 1865     | 0       | 65       | 69                |
| 336     | 241      | 506     | 627      | 153               |
| 396     | 361      | 484     | 491      | 35                |
| 1020    | 1075     | 180     | 62       | 130               |

Cursor accuracy test for user 3

| Mouse X | Target X | Mouse Y | Target Y | Distance (pixels) |
|---------|----------|---------|----------|-------------------|
| 120     | 240      | 108     | 105      | 120               |
| 144     | 41       | 108     | 107      | 103               |
| 600     | 574      | 720     | 580      | 142               |
| 1752    | 1889     | 672     | 604      | 152               |
| 1824    | 1878     | 224     | 198      | 59                |
| 48      | 82       | 648     | 704      | 65                |
| 1728    | 1865     | 96      | 65       | 140               |
| 336     | 241      | 648     | 627      | 97                |
| 456     | 361      | 504     | 491      | 95                |
| 1104    | 1075     | 64      | 62       | 29                |

Cursor accuracy test for user 4

| Mouse X | Target X | Mouse Y | Target Y | Distance (pixels) |
|---------|----------|---------|----------|-------------------|
| 280     | 240      | 140     | 105      | 53                |
| 0       | 41       | 140     | 107      | 52                |
| 580     | 574      | 644     | 580      | 64                |
| 1880    | 1889     | 728     | 604      | 124               |
| 1840    | 1878     | 224     | 198      | 46                |
| 180     | 82       | 644     | 704      | 114               |
| 1740    | 1865     | 112     | 65       | 133               |
| 400     | 241      | 560     | 627      | 172               |
| 420     | 361      | 532     | 491      | 71                |
| 1160    | 1075     | 56      | 62       | 85                |

Cursor accuracy test for user 5

| Mouse X | Target X | Mouse Y | Target Y | Distance (pixels) |
|---------|----------|---------|----------|-------------------|
| 300     | 240      | 72      | 105      | 68                |
| 100     | 41       | 96      | 107      | 60                |
| 620     | 574      | 696     | 580      | 124               |
| 1820    | 1889     | 672     | 604      | 96                |
| 1880    | 1878     | 240     | 198      | 42                |
| 260     | 82       | 528     | 704      | 250               |
| 1919    | 1865     | 120     | 65       | 77                |
| 280     | 241      | 528     | 627      | 106               |
| 360     | 361      | 456     | 491      | 35                |
| 1120    | 1075     | 24      | 62       | 58                |

Appendix D – Questionnaire
--------------------------

![](media/09867334b3989750341b2d9fdc96bf6b.png)

Feedback from User 1

| No. | Question                                               | Score |
|-----|--------------------------------------------------------|-------|
| 1   | The application was easy to use.                       | 4     |
| 2   | The instructions were easy to follow.                  | 3     |
| 3   | System was able to detect the pupil most of the times. | 2     |
| 4   | System moved cursor to gaze point most of the times.   | 2     |
| 5   | System provided enough information for error messages. | 5     |

Feedback from User 2

| No. | Question                                               | Score |
|-----|--------------------------------------------------------|-------|
| 1   | The application was easy to use.                       | 5     |
| 2   | The instructions were easy to follow.                  | 4     |
| 3   | System was able to detect the pupil most of the times. | 3     |
| 4   | System moved cursor to gaze point most of the times.   | 2     |
| 5   | System provided enough information for error messages. | 5     |

Feedback from User 3

| No. | Question                                               | Score |
|-----|--------------------------------------------------------|-------|
| 1   | The application was easy to use.                       | 5     |
| 2   | The instructions were easy to follow.                  | 5     |
| 3   | System was able to detect the pupil most of the times. | 2     |
| 4   | System moved cursor to gaze point most of the times.   | 1     |
| 5   | System provided enough information for error messages. | 4     |

Feedback from User 4

| No. | Question                                               | Score |
|-----|--------------------------------------------------------|-------|
| 1   | The application was easy to use.                       | 5     |
| 2   | The instructions were easy to follow.                  | 5     |
| 3   | System was able to detect the pupil most of the times. | 4     |
| 4   | System moved cursor to gaze point most of the times.   | 4     |
| 5   | System provided enough information for error messages. | 5     |

Feedback from User 5

| No. | Question                                               | Score |
|-----|--------------------------------------------------------|-------|
| 1   | The application was easy to use.                       | 4     |
| 2   | The instructions were easy to follow.                  | 4     |
| 3   | System was able to detect the pupil most of the times. | 4     |
| 4   | System moved cursor to gaze point most of the times.   | 4     |
| 5   | System provided enough information for error messages. | 5     |
