
import cv2
import numpy as np

# Read the image
image = cv2.imread('scenery.jpg') 


angle = 45
scale_factor = 0.5
tx = 100
ty = 50


height, width = image.shape[:2]


rotation_matrix = cv2.getRotationMatrix2D((width / 2, height / 2), angle, scale_factor)

rotated_image = cv2.warpAffine(image, rotation_matrix, (width, height))


translation_matrix = np.float32([[1, 0, tx], [0, 1, ty]])


translated_image = cv2.warpAffine(image, translation_matrix, (width, height))


cv2.imshow('Original Image', image)
cv2.imshow('Rotated Image', rotated_image)
cv2.imshow('Translated Image', translated_image)

cv2.waitKey(0)
cv2.destroyAllWindows()