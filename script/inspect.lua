local escaping_rules = {
  { '\\', '\\\\' },
  { '"', '\\"' },
  { '\n', '\\n' },
  { '\t', '\\t' },
  { '\a', '\\a' },
  { '\b', '\\b' },
  { '\f', '\\f' },
  { '\v', '\\v' },
}

local function escape (s)
  for _,rule in ipairs(escaping_rules) do
    s = s:gsub(rule[1], rule[2])
  end

  return s
end

local function inspect_table (t, level, indent)
  level = level or 0
  indent = indent or '  '

  local r = '{\n'
  for k,v in pairs(t) do
    local key
    if type(k) == 'string' and k == escape(k) then
      key = k
    elseif type(k) == 'table' then
      key = string.format('[%s]', inspect_table(k, level + 1, indent))
    else
      key = string.format('[%s]', inspect(k))
    end

    local value
    if type(v) == 'table' then
      value = inspect_table(v, level + 1)
    else
      value = inspect(v)
    end

    r = r .. indent:rep(level + 1) ..  string.format('%s = %s,\n', key, value)
  end

  r = r .. string.rep(indent, level) .. '}'
  return r
end

local function inspect (value, level, indent)
  level = level or 0
  indent = indent or '  '

  local repr
  if type(value) == 'string' then
    repr = string.format('"%s"', escape(value))
  elseif type(value) == 'table' then
    repr = inspect_table(value, level, indent)
  else
    repr = value
  end

  return string.rep(indent, level) .. repr
end

return inspect
