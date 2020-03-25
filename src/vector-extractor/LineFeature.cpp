#include "LineFeature.h"

LineFeature::LineFeature(OGRFeature *feature) : feature(feature) {
    line = feature->GetGeometryRef()->toLineString();
    point_count = line->getNumPoints();
}

std::map<std::string, std::string> LineFeature::get_attributes() {
    std::map<std::string, std::string> ret;

    for (auto &&oField: *feature) {
        ret[oField.GetName()] = oField.GetAsString();
    }

    return ret;
}

std::string LineFeature::get_attribute(const std::string& name) {
    return feature->GetFieldAsString(name.c_str());
}

std::vector<double> LineFeature::get_line_point(int index) {
    return std::vector<double>{line->getX(index), line->getY(index), line->getZ(index)};
}

int LineFeature::get_point_count() {
    return point_count;
}