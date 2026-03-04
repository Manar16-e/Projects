'''import os,shutil
path = r"C:/Users/Manar/Downloads/" 

#ide = organisere fra den current path du arbejder med

#Do Folders and check type files and store them correctly

#Shows all files in the path with their path
os.listdir(path)
files = os.listdir(path)

#Create the folders 
folder_names = ["csv files", "python files", "pdf files", "txt files", "jpg files", "png files", "mp3 files", "mp4 files", "zip files", "exe files", "other files"]

for loop in range(len(folder_names)):
    if not os.path.exists(path+ folder_names[loop]):
        os.makedirs(path+ folder_names[loop])

#Move the files to the correct folder
for file in files:
    if ".pdf" in file and not os.path.exists(path + "pdf files/" + file):   #If a file ending in csv isnot in the path with the correct folder, it will be moved
        shutil.move(path+file, path+ "pdf files/"+file)
    elif ".csv" in file and not os.path.exists(path+ "csv files/"+file):
        shutil.move(path+file, path+ "csv files/"+file)
    elif ".txt" in file and not os.path.exists(path+ "txt files/"+file):
        shutil.move(path+file, path+ "txt files/"+file)
    elif ".jpg" in file and not os.path.exists(path+ "jpg files/"+file):
        shutil.move(path+file, path+ "jpg files/"+file)
    elif ".png" in file and not os.path.exists(path+ "png files/"+file):
        shutil.move(path+file, path+ "png files/"+file)
    elif ".mp3" in file and not os.path.exists(path+ "mp3 files/"+file):
        shutil.move(path+file, path+ "mp3 files/"+file)
    elif ".mp4" in file and not os.path.exists(path+ "mp4 files/"+file):
        shutil.move(path+file, path+ "mp4 files/"+file)
    elif ".zip" in file and not os.path.exists(path+ "zip files/"+file):    
        shutil.move(path+file, path+ "zip files/"+file)
    elif ".py" in file and not os.path.exists(path+ "python files/"+file):
        shutil.move(path+file, path+ "python files/"+file)

'''