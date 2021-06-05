#define private public

#include "../src/money.h"
#include <catch2/catch.hpp>

TEST_CASE("Initial frames are random, between 100 and 400", "[money]")
{
  Resources r{};
  for (int i = 0; i < 5; i++)
  {
    Money money{1.0, r};
    REQUIRE((money.total_frames >= 100 && money.total_frames <= 400));
  }
}

TEST_CASE("Start point is random, with an offset of +/- 10", "[money]")
{
  Resources r{};
  for (int i = 0; i < 5; i++)
  {
    Money money{1.0, r};
    REQUIRE((money.start_point.x >= 1045.0 && money.total_frames <= 1065.0));
    REQUIRE((money.start_point.y >= 700.0 && money.total_frames <= 720.0));
  }
}

TEST_CASE("Middle point is random, with an offset of +/- 300", "[money]")
{
  Resources r{};
  for (int i = 0; i < 5; i++)
  {
    Money money{1.0, r};
    REQUIRE((money.mid_point.x >= 905.0 && money.total_frames <= 1505.0));
    REQUIRE((money.mid_point.y >= 700.0 && money.total_frames <= 1300.0));
  }
}

TEST_CASE("Texture changes depending on the value", "[money]")
{
  Resources r{};
  Money money1{1.0, r};
  Money money2{15.0, r};
  Money money3{25.0, r};
  Money money4{35.0, r};
  Money money5{45.0, r};
  REQUIRE(money1.sprite.getTexture() ==
          &r.get_texture(ResourceName::COIN_TEXTURE_1));
  REQUIRE(money2.sprite.getTexture() ==
          &r.get_texture(ResourceName::COIN_TEXTURE_2));
  REQUIRE(money3.sprite.getTexture() ==
          &r.get_texture(ResourceName::COIN_TEXTURE_3));
  REQUIRE(money4.sprite.getTexture() ==
          &r.get_texture(ResourceName::COIN_TEXTURE_4));
  REQUIRE(money5.sprite.getTexture() ==
          &r.get_texture(ResourceName::COIN_TEXTURE_5));
}

TEST_CASE("Scale increases when rendering the first half of frames", "[money]")
{
  Resources r{};
  sf::RenderWindow w{};
  Money money{1.0, r};
  const int frames = static_cast<int>(money.total_frames / 2);
  const float increment = 1.002f;
  const auto expected_scale = static_cast<float>(money.sprite.getScale().x *
                                                 std::pow(increment, frames));

  for (int i = 0; i < frames; i++)
    money.render(w);

  float current_scale = money.sprite.getScale().x;
  REQUIRE(expected_scale == Approx(current_scale));
}

TEST_CASE("Scale decreases when rendering the second half of frames", "[money]")
{
  Resources r{};
  sf::RenderWindow w{};
  Money money{1.0, r};

  int frames = static_cast<int>(money.total_frames / 2);
  for (int i = 0; i < frames; i++)
    money.render(w);

  const float decrement = 0.991f;
  const auto expected_scale = static_cast<float>(money.sprite.getScale().x *
                                                 std::pow(decrement, frames));

  for (int i = 0; i < frames; i++)
    money.render(w);

  float current_scale = money.sprite.getScale().x;
  REQUIRE(expected_scale == Approx(current_scale));
}

TEST_CASE("Rendering when there are no frames left does nothing", "[money]")
{
  Resources r{};
  sf::RenderWindow w{};
  Money money{1.0, r};

  int frames = static_cast<int>(money.total_frames);
  for (int i = 0; i < frames; i++)
  {
    money.render(w);
  }
  REQUIRE(!money.has_more_frames());
  float final_scale = money.sprite.getScale().x;
  money.render(w);
  REQUIRE(final_scale == money.sprite.getScale().x);
}

TEST_CASE("Quadratic Bezier curve is calculated correctly", "[money]")
{
  Resources r{};
  Money money{1.0, r};
  money.start_point = sf::Vector2f(1000.0f, 350.0f);
  money.mid_point = sf::Vector2f(750.0f, 1750.0f);
  money.end_point = sf::Vector2f(1750.0f, 750.0f);

  CHECK(953.125f == money.calc_bezier_curve(0.25f).x);
  CHECK(900.0f == money.calc_bezier_curve(0.25f).y);
  CHECK(1062.5f == money.calc_bezier_curve(0.50f).x);
  CHECK(1150.0f == money.calc_bezier_curve(0.50f).y);
  CHECK(1328.125f == money.calc_bezier_curve(0.75f).x);
  CHECK(1100.0f == money.calc_bezier_curve(0.75f).y);
}