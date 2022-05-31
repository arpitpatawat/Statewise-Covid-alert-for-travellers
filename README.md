# Statewise-Covid-alert-for-travellers (Hardware + Simulation)
My proposed model for live tracking the COVID
data involves using the real time data as uploaded by
common and reliable website sources. I am
scraping the data of use, that involves counts such as
total cases of a particular state or active cases of a
particular state, etc. Then I pass this data to our
LCD using a Wi-Fi module of NodeMCU(ESP8266)
and display it to our users.
The alert system works on a simple if and else
condition. Similar to a tracking system, I parse in
the active number of active cases, of a particular
state, as our conditional statement. I am also fixing a
threshold value that acts as an indicator to our alert
system and if the threshold limit is breached by the
active number of cases, I activate the alert
systems.The social distance detector uses an ultrasonic
distance sensor to find the range of another being
within 6-feet and it comes with an added buzzer that
turns on when the distance is less than 6-feet.

**A.	Live Data Tracker:**
- a.	The live count is fetched from Zee news’ official website.
- b.	The Scrapped data is auto-updated in ThingSpeack Cloud.
- c.	The Arduino is coded in an online editor and then is burned with our NodeMCU.
- d.	The LCD is connected with our NodeMCU to display our live data.


**B.	E-mail Alert System:**
- a.	The electronic mail system employs coding in MATLAB.
- b.	The implementation is done using conditional branching in MATLAB.
- c.	The number of active cases is considered and based on it an alert is sent to the fed email address of user.


**C.	Social Distance Detector:**
- a.	The software simulation of social distance detector is demonstrated using Tinkercad.
- b.	It uses ultraviolet sensors that detect the distance if a particular object enters its range.
- c.	It is added with a buzzer which starts when the range is less than the specified limit.

![image](https://user-images.githubusercontent.com/75129076/171166169-3b56248a-c882-4b56-9436-0592401a789f.png)

![flow chart](https://user-images.githubusercontent.com/75129076/171164288-09d3e057-20dd-49e2-a4da-44a522cb8368.png)

<span >
<img src="https://user-images.githubusercontent.com/75129076/171164367-1edf2be9-2a09-4f59-90bd-878ad5c9c0c6.png" width ="400" height ="400" >
<img src="https://user-images.githubusercontent.com/75129076/171164434-8ed4fb62-793e-433f-b619-2033f145cfea.png"  width ="400" height ="400">
 </span>
 <span >
<img src="https://user-images.githubusercontent.com/75129076/171165444-efe18af6-9efb-486d-934b-e8330540b40c.png" width ="400" height ="400">
<img src="https://user-images.githubusercontent.com/75129076/171164454-25d9ee8d-74d9-4d78-9613-71abfa91a9e9.png" width ="400" height ="400" >
<!-- <img src="(https://user-images.githubusercontent.com/75129076/171164474-b479066a-84bc-450d-93c2-120133180b36.png" width ="400" height ="400" > -->
   </span>
    <span >
<img src="https://user-images.githubusercontent.com/75129076/171164499-4137b8e2-e205-4a7a-92b4-e297b5199570.png" width ="400" height ="400" >
  </span>
<img src="https://user-images.githubusercontent.com/75129076/171164505-7fe57382-d214-4712-9051-79db86c4ae05.png" >
  
<!-- ![tinkercad circuit](https://user-images.githubusercontent.com/75129076/171164230-29c7377f-858c-4969-8b80-7c2936025726.png) -->
![image](https://user-images.githubusercontent.com/75129076/171165856-d2812a8e-1267-4765-9169-80975d028f14.png)

Video of the project is uploaded [Here](https://drive.google.com/file/d/1YIlVdw47IWR-8FAu77oOAwTqqlZucJhr/view?usp=sharing)
