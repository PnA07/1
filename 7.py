import cv2
import numpy as np
image_path="images/abc.jpg"
img=cv2.imread(image_path)
if image_path is None:
    print("Image not found")
else:
    height,width=img.shape[:2]

    mid_x=width//2
    mid_y=height//2

    top_left=img[0:mid_y,0:mid_x]
    top_right=img[0:mid_y,mid_x:width]
    bottom_left=img[mid_y:height,0:mid_x]
    bottom_right=img[mid_y:height,mid_x:width]

    cv2.imwrite('top_left.jpg',top_left)
    cv2.imwrite('top_right.jpg',top_right)
    cv2.imwrite('bottom_left.jpg',bottom_left)
    cv2.imwrite('bottom_right.jpg',bottom_right)
    print("Quadrants saved successfully")
    cv2.waitKey(0)
    cv2.destroyAllWindows()