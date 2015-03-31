var
  a:array[1..100,1..100] of char;
  n,m,i,j,k:longint;
  s:string;
  flag:boolean;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(s);
      for j:=1 to n do a[i,j]:=s[j];
    end;
  for i:=1 to n do
    begin
      flag:=false;
      for j:=1 to n do
        if a[i,j]='.' then flag:=true;
      if not flag then break;
    end;
  if flag then
    begin
      for i:=1 to n do
        begin
          for j:=1 to n do if a[i,j]='.' then break;
          writeln(i,' ',j);
        end;
      readln;
      halt;
    end;
  for i:=1 to n do
    begin
      flag:=false;
      for j:=1 to n do
        if a[j,i]='.' then flag:=true;
      if not flag then break;
    end;
  if flag then
    begin
      for i:=1 to n do
        begin
          for j:=1 to n do if a[j,i]='.' then break;
          writeln(j,' ',i);
        end;
      readln;
      halt;
    end;
  writeln(-1);
  readln;
end.