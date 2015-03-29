var
  a:array[1..9,1..9] of longint;
  n,i,j,p,q:longint;
function pan:boolean;
var
  i,j,p,q:longint;
  f:array[1..9] of 0..1;
begin
  for i:=1 to 9 do
    begin
      fillchar(f,sizeof(f),0);
      for j:=1 to 9 do f[a[i,j]]:=1;
      for j:=1 to 9 do if f[j]=0 then exit(false);
    end;
  for i:=1 to 9 do
    begin
      fillchar(f,sizeof(f),0);
      for j:=1 to 9 do f[a[j,i]]:=1;
      for j:=1 to 9 do if f[j]=0 then exit(false);
    end;
  for i:=1 to 3 do
    for j:=1 to 3 do
      begin
        fillchar(f,sizeof(f),0);
        for p:=3*i-2 to 3*i do
          for q:=3*j-2 to 3*j do
            f[a[p,q]]:=1;
        for p:=1 to 9 do if f[p]=0 then exit(false);
      end;
end;
begin
  readln(n);
  for i:=1 to n do
    begin
      for p:=1 to 9 do for q:=1 to 9 do read(a[p,q]);
      if pan then writeln('Right') else writeln('Wrong');
    end;
end.