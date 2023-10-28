import cv2 as cv

# Load image
image = cv.imread('C:/PVBI_Lenguaje_C_932/Actividades/PVBI_OpenCV_0_932/image.PNG')

#Change color
grayscale_image = cv.cvtColor(image, cv.COLOR_BGR2GRAY)

#Display new image
cv.imwrite('imagen_bn.PNG', grayscale_image)
cv.imshow('Imagen en Blanco y Negro', grayscale_image)
cv.waitKey(0)
cv.destroyAllWindows()


