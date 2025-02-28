

import cv2


image = cv2.imread('scenery.jpg') 


blurred = cv2.GaussianBlur(image, (15, 15), 0)


smoothed = cv2.bilateralFilter(image, 5, 50, 50)


cv2.imshow('Original Image', image)
cv2.imshow('Blurred Image', blurred)
cv2.imshow('Smoothed Image', smoothed)
cv2.waitKey(0)
cv2.destroyAllWindows()