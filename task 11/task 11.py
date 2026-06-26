import cv2
import numpy as np

image=cv2.imread("test.jpg")

gray=cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)

ret,mask=cv2.threshold(gray,240,255,cv2.THRESH_BINARY_INV)

contours,hierarchy=cv2.findContours(mask.copy(),cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)

sorted_contours=sorted(contours,key=cv2.contourArea,reverse=True)

largest_contour=sorted_contours[0]

x,y,w,h=cv2.boundingRect(largest_contour)

center_x = int(x + w / 2)
center_y = int(y + h / 2)

cv2.rectangle(image, (x, y), (x + w, y + h), (0, 0, 255), 3)

cv2.circle(image, (center_x,center_y), 5, (0, 0, 255), -1)

cv2.imshow("result", image)
cv2.waitKey(0)
cv2.destroyAllWindows()