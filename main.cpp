#include "src/device.h"

bool Init(Scene *scene) {
	Skybox::Desc skyd;
	skyd.filenames[0] = "../radar/data/default_diff.png";
	skyd.filenames[1] = "../radar/data/default_diff.png";
	skyd.filenames[2] = "../radar/data/default_diff.png";
	skyd.filenames[3] = "../radar/data/default_diff.png";
	skyd.filenames[4] = "../radar/data/default_diff.png";
	skyd.filenames[5] = "../radar/data/default_diff.png";
	Skybox::Handle sky = scene->Add(skyd);
	if (sky < 0) {
		LogErr("Error loading skybox.");
		return false;
	}
	//scene->SetSkybox(sky);

	return true;
}

void FixedUpdate(Scene *scene, float dt) {

}

void Update(Scene *scene, float dt) {

}

int main() {
	Log::Init();

	Device &device = GetDevice();
	if (!device.Init(Init)) {
		printf("Error initializing Device. Aborting.\n");
		DestroyDevice();
		Log::Close();
		system("PAUSE");
		return 1;
	}

	device.SetUpdateFunc(Update);
	device.SetFixedUpdateFunc(FixedUpdate);

	device.Run();

	DestroyDevice();
	Log::Close();

	return 0;
}