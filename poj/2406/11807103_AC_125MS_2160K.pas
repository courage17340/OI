var
  s:ansistring;
  n,i,j,L:longint;
  flag:boolean;
function yes(x:longint):boolean;
var
  i,j:longint;
begin
  for i:=1 to L-x do
    if s[i]<>s[i+x] then exit(false);
  exit(true);
end;
begin
  while true do
    begin
      flag:=true;
      readln(s);
      if s='.' then break;
      L:=length(s);
      for i:=1 to L shr 1 do
        if (L mod i=0)and yes(i) then
          begin
            writeln(L div i);
            flag:=false;
            break;
          end;
      if flag then writeln(1);
    end;
end.