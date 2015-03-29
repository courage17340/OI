var
  a:array[1..500] of longint;
  f:array[0..1000000] of boolean;
  n,k,i,j,m,p:longint;
  flag:boolean;
begin
  readln(k);
  for p:=1 to k do
    begin
      readln(n);
      for i:=1 to n do readln(a[i]);
      for m:=n to 1000000 do
        begin
          fillchar(f,sizeof(f),0);
          flag:=true;
          for i:=1 to n do
            if f[a[i] mod m] then
              begin
                flag:=false;
                break;
              end
                else f[a[i] mod m]:=true;
          if flag then break;
        end;
      writeln(m);
    end;
end.