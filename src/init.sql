drop table if exists products;

create table products(
  id integer primary key,
  title text not null,
  slug text not null unique,
  description text,
  base_price numeric not null default 0.0,
  insert_at bigint not null default (unixepoch()),
  updated_at bigint not null default (unixepoch())
);

insert into products (title, slug, description, base_price)
values('Hamburger','hamburger','A bun with a patty inside', 42.0);
