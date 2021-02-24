# LFSREncryption
This program takes advantage of linear-feedback shift registers to encrypt a photo by randomly changing the pixel values based on XOR operations.

* Read three arguments from the command line: source image filename, output image filename, and the FibLFSR seed.
* Utilize SFML to load the local source image and display it in its individual window.
* Use the FibLFSR class to encode/decode the image.
* Display the encoded/decoded image in its indivual window.
* Save the updated image to the local disk.
