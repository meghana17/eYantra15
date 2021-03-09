################################################################################
################################################################################

                               ## TEAM DETAILS ##
'''
e-Yantra 2015
Task 1 - Digit Recognition
eYRC
Team ID: eYRC#1011
File name: eYRC#1011_ImageProcessing.py
Version: 1.0.0
Author: Meghana B
'''

                            ## PROGRAM DESCRIPTION ##
'''
This is a program that identifies the digits in the grids and tracks the location 
of each number as well. 
'''

################################################################################
################################################################################

import numpy as np
import cv2

def train(img):
    '''
    To be executed in training mode as specified from calling function
    img-- a single test image as input argument
    samples-- List containing sample truncated images of digits
    responses-- List containing corresponding user trained examples
    '''
    img_orig = img
    img = img.copy()
    d1 = img[57:396,90:344]
    d2 = img[524:1024,90:429]
    gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    ret,thresh = cv2.threshold(gray,127,255,cv2.THRESH_BINARY)
    contours,hierarchy = cv2.findContours(thresh,cv2.RETR_LIST,cv2.CHAIN_APPROX_SIMPLE)
    contourNew = []
    #Isolate contours of digits alone
    for i in range(1,(len(contours)-1)):
        if ((cv2.contourArea(contours[i])> 400) & (cv2.contourArea(contours[i])<10000)):
            contourNew.append(contours[i])
    #Initialize variable
    samples =  np.empty((0,100))
    responses = []
    #Keyboard Digits in ASCII 0 to 9 stored in keys
    keys = [i for i in range(48,58)]

    for cnt in contourNew:
        #To ignore internal contours, if any
        if cv2.contourArea(cnt)>50:
            [x,y,w,h] = cv2.boundingRect(cnt)
        #Draw Rectangle and await for input for each detected digit
            if  h>50:
                cv2.rectangle(img,(x,y),(x+w,y+h),(0,0,255),2)
                roi = thresh[y:y+h,x:x+w]
                roismall = cv2.resize(roi,(10,10))
                cv2.imshow('norm',img)
                key = cv2.waitKey(0)

                if key == 27:  # (escape to quit)
                    sys.exit()
                elif key in keys:#Corresponding key typed is stored as a response
                    responses.append(int(chr(key)))
                    sample = roismall.reshape((1,100))
                    samples = np.append(samples,sample,0)

    responses = np.array(responses,np.float32)
    responses = responses.reshape((responses.size,1))
    print ("training complete")
    return samples,responses


def play(img):
    '''
    img-- a single test image as input argument
    No_pos_D1 -- List containing detected numbers in Division D1
    No_pos_D2 -- List of pair [grid number, value]

    '''
    #Initialization and D1 and D2 separation
    img_orig = img
    img = img_orig.copy()
    d1 = img[57:396,90:344]
    d2 = img[524:1024,90:429]
    #Load training set
    samples = np.loadtxt('generalsamples.data',np.float32)
    responses = np.loadtxt('generalresponses.data',np.float32)
    responses = responses.reshape((responses.size,1))

    No_pos_D1 = []
    No_pos_D2 = []
    D2tuple = ()
    #Create KNearest Object called model
    model = cv2.KNearest()
    model.train(samples,responses)

    width = 110
    height = 115
    imagesD = [img]
    #Isolate each square from D1 and D2 
    for j in range (0,4):
        for i in range (0,3):
            imagesD.append(d1[j*height:(j+1)*height,i*width:(i+1)*width])      
    for j in range(0,6):
        for i in range(0,4):
            imagesD.append(d2[j*height:(j+1)*height,i*width:(i+1)*width])

    for cell,images in enumerate(imagesD):
        numbers = []
        contours = []
        gray = cv2.cvtColor(images,cv2.COLOR_BGR2GRAY)
        ret,thresh = cv2.threshold(gray,127,255,cv2.THRESH_BINARY)
        contours, hierarchy = cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
        contoursNew =[]

        for i in range(0,len(contours)):
            if cv2.contourArea(contours[i])>400 and cv2.contourArea(contours[i])<10000:
                contoursNew.append(contours[i])
        #Display the original image with detected digit contours
        if cell == 0:
            cv2.drawContours(img_orig,contoursNew,-1,(0,255,0),3)
            cv2.imshow('OCR',img_orig)
        #Detect each digit
        else:
            contoursNew = list(reversed(contoursNew))
            #For More than one digit arrange contours from left to right
            if cell > 12 and contoursNew != []:
                Mprev = cv2.moments(contoursNew[0])
                Mnext = cv2.moments(contoursNew[1])
                cxprev = int(Mprev['m10']/Mprev['m00'])
                cxnext = int(Mnext['m10']/Mnext['m00'])
                if cxprev > cxnext:
                    contoursNew = list(reversed(contoursNew))
            #Isolate each digit and assign a number based on nearest match in the training set
            for cnt in contoursNew:
                [x,y,w,h] = cv2.boundingRect(cnt)
                if h>30:
                    cv2.rectangle(images,(x,y),(x+w,y+h),(0,255,0),2)
                    roi = thresh[y:y+h,x:x+w]
                    roismall = cv2.resize(roi,(10,10))
                    roismall = roismall.reshape((1,100))
                    roismall = np.float32(roismall)
                    retval, results, neigh_resp, dists = model.find_nearest(roismall, k = 1)
                    number = int(results[0][0])
                    numbers.append(number)
            #Assignment to No_pos_D1 and No_pos_D2
            if cell > 12 and numbers != []:
                value = numbers[0]*10 + numbers[1]*1
                D2tuple = ((cell-13),value)
                No_pos_D2.append(D2tuple)
            elif cell <= 12 and numbers != []:
                No_pos_D1.append(numbers[0])
        
    return No_pos_D1, No_pos_D2


if __name__ == "__main__":
    img = cv2.imread('test_image1.jpg')
    '''
    mode = input('Enter training mode?\n Enter 1 for Yes.\n Enter any other key for a predefined training set\n')
    if mode == 1:
        #code for training the data
        samples,responses = train(img)
        np.savetxt('generalsamples.data',samples)
        np.savetxt('generalresponses.data',responses)
    '''
    #code for checking output for single image
    No_pos_D1,No_pos_D2 = play(img)
    print No_pos_D1
    print No_pos_D2
    cv2.waitKey(0)
    cv2.destroyAllWindows()



