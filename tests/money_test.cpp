#define private public

#include "../src/gui/drawables/money.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cmath>

namespace money_test
{
Resources r{};

TEST_CASE("Money objects are initialised correctly", "[money]")
{
  SECTION("Texture changes depending on the value")
  {
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

  for (int i = 0; i < 5; i++)
  {
    Money money{1.0, r};

    SECTION("Initial frames are random, between 40 and 160")
    {
      REQUIRE((money.total_frames >= 40 && money.total_frames <= 160));
    }

    SECTION("Initial frames are always an even number")
    {
      REQUIRE(money.total_frames % 2 == 0);
    }

    SECTION("Start point is random, with an offset of +/- 10")
    {
      REQUIRE((money.start_point.x >= 1045.0 && money.total_frames <= 1065.0));
      REQUIRE((money.start_point.y >= 700.0 && money.total_frames <= 720.0));
    }

    SECTION("Middle point is random, with an offset of +/- 300")
    {
      REQUIRE((money.mid_point.x >= 905.0 && money.total_frames <= 1505.0));
      REQUIRE((money.mid_point.y >= 700.0 && money.total_frames <= 1300.0));
    }
  }
}

TEST_CASE("Money objects are rendered correctly", "[money]")
{
  sf::RenderWindow w{};
  Money money{1.0, r};
  const int half_frames = money.total_frames / 2;
  auto last_known_scale_x = money.sprite.getScale().x;
  auto last_known_scale_y = money.sprite.getScale().y;

  SECTION("Scale increases when rendering the first half of frames")
  {
    for (int i = 0; i < half_frames; i++)
    {
      w.draw(money);
      auto current_scale_x = money.sprite.getScale().x;
      auto current_scale_y = money.sprite.getScale().y;
      REQUIRE(current_scale_x > last_known_scale_x);
      REQUIRE(current_scale_y > last_known_scale_y);
      last_known_scale_x = current_scale_x;
      last_known_scale_y = current_scale_y;
    }
  }

  SECTION("Scale decreases when rendering the second half of frames")
  {
    for (int i = 0; i < half_frames; i++)
      w.draw(money);

    last_known_scale_x = money.sprite.getScale().x;
    last_known_scale_y = money.sprite.getScale().y;

    for (int i = 0; i < half_frames; i++)
    {
      w.draw(money);
      auto current_scale_x = money.sprite.getScale().x;
      auto current_scale_y = money.sprite.getScale().y;
      REQUIRE(current_scale_x < last_known_scale_x);
      REQUIRE(current_scale_y < last_known_scale_y);
      last_known_scale_x = current_scale_x;
      last_known_scale_y = current_scale_y;
    }
  }

  SECTION("Rendering when there are no frames left does nothing")
  {
    for (int i = 0; i < money.total_frames; i++)
      w.draw(money);

    last_known_scale_x = money.sprite.getScale().x;
    last_known_scale_y = money.sprite.getScale().y;
    w.draw(money);
    auto current_scale_x = money.sprite.getScale().x;
    auto current_scale_y = money.sprite.getScale().y;
    REQUIRE(current_scale_x == last_known_scale_x);
    REQUIRE(current_scale_y == last_known_scale_y);
  }
}

TEST_CASE("Quadratic Bezier curve is calculated correctly", "[money]")
{
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
} // namespace money_test