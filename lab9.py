# Read an image and extract and display low-level features such as edges, textures using filtering techniques.

import cv2
# Read the image
image_path = "img9.png" # Replace "your_image.jpg" with the path to your image
image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
if image is None:
    print("Failed to load the image.")
else:
    # Display the original image
    cv2.imshow("Original Image", image)
    # Apply Canny Edge Detection
    canny_edges = cv2.Canny(image, 100, 200)
    # Display image with Canny Edges
    cv2.imshow("Canny Edges", canny_edges)
    # Apply Sobel filter to extract edges
    sobel_x = cv2.Sobel(image, cv2.CV_64F, 1, 0, ksize=3)
    sobel_y = cv2.Sobel(image, cv2.CV_64F, 0, 1, ksize=3)
    sobel_edges = cv2.magnitude(sobel_x, sobel_y)
    sobel_edges = cv2.normalize(sobel_edges, None, 0, 255, cv2.NORM_MINMAX, dtype=cv2.CV_8U)
    # Display edges extracted using Sobel filter
    cv2.imshow("Edges (Sobel Filter)", sobel_edges)
    # Apply Laplacian filter to extract edges
    laplacian_edges = cv2.Laplacian(image, cv2.CV_64F)
    laplacian_edges = cv2.normalize(laplacian_edges, None, 0, 255, cv2.NORM_MINMAX, dtype=cv2.CV_8U)
    # Display edges extracted using Laplacian filter
    cv2.imshow("Edges (Laplacian Filter)", laplacian_edges)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
