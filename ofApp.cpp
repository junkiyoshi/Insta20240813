#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);

	ofEnableDepthTest();
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	int width = 600;
	int height = 600;
	int len = 200;
	for (int z = -200; z <= 200; z += 20) {

		auto tmp_len = len * ofMap(z, -200, 200, 1, 0.5);
		auto color_value = ofMap(z, -200, 200, 239, 39);

		auto move_x = ofMap(ofNoise(39, (z + 200) * 0.0025 + ofGetFrameNum() * 0.01), 0, 1, -tmp_len, tmp_len);
		move_x = move_x * ofMap(z, -200, 200, 0.9, 0.5);

		auto move_y = ofMap(ofNoise(1039, (z + 200) * 0.0025 + ofGetFrameNum() * 0.01), 0, 1, -tmp_len, tmp_len);
		move_y = move_y * ofMap(z, -200, 200, 0.9, 0.5);

		ofPushMatrix();
		ofTranslate(move_x, move_y, z);

		ofFill();
		ofSetColor(color_value);

		ofBeginShape();

		ofVertex(glm::vec2(width * -0.5, height * -0.5));
		ofVertex(glm::vec2(width * 0.5, height * -0.5));
		ofVertex(glm::vec2(width * 0.5, height * 0.5));
		ofVertex(glm::vec2(width * -0.5, height * 0.5));

		ofNextContour(true);

		ofVertex(glm::vec2(width * -0.5 + tmp_len, height * -0.5 + tmp_len));
		ofVertex(glm::vec2(width * 0.5 - tmp_len, height * -0.5 + tmp_len));
		ofVertex(glm::vec2(width * 0.5 - tmp_len, height * 0.5 - tmp_len));
		ofVertex(glm::vec2(width * -0.5 + tmp_len, height * 0.5 - tmp_len));

		ofEndShape(true);

		ofNoFill();
		ofSetColor(239, 139, 239);

		ofBeginShape();

		ofVertex(glm::vec2(width * -0.5, height * -0.5));
		ofVertex(glm::vec2(width * 0.5, height * -0.5));
		ofVertex(glm::vec2(width * 0.5, height * 0.5));
		ofVertex(glm::vec2(width * -0.5, height * 0.5));

		ofNextContour(true);

		ofVertex(glm::vec2(width * -0.5 + tmp_len, height * -0.5 + tmp_len));
		ofVertex(glm::vec2(width * 0.5 - tmp_len, height * -0.5 + tmp_len));
		ofVertex(glm::vec2(width * 0.5 - tmp_len, height * 0.5 - tmp_len));
		ofVertex(glm::vec2(width * -0.5 + tmp_len, height * 0.5 - tmp_len));

		ofEndShape(true);

		ofPopMatrix();
	}

	this->cam.end();

	/*
	int start = 125;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}