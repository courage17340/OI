var
  a:array[1..6] of longint;
  i,ans:longint;
function sum:longint;
var
  i:longint;
begin
  sum:=0;
  for i:=1 to 6 do inc(sum,a[i]);
end;
begin
  while true do
    begin
      for i:=1 to 6 do read(a[i]);readln;
      if sum=0 then break;
      ans:=a[6];a[6]:=0;
      a[1]:=a[1]-a[5]*11;if a[1]<0 then a[1]:=0;
      ans:=ans+a[5];a[5]:=0;
      ans:=ans+a[4];
      if a[2]>=a[4]*5 then
        begin
          a[2]:=a[2]-a[4]*5;
          a[4]:=0;
        end
        else
          begin
            a[1]:=a[1]-(20*a[4]-4*a[2]);
            if a[1]<0 then a[1]:=0;
            a[2]:=0;
            a[4]:=0;
          end;
      ans:=ans+a[3] shr 2;
      a[3]:=a[3] mod 4;
      if a[3]>0 then
        begin
          inc(ans);
          if a[2]<=7-a[3]*2 then
            begin
              a[1]:=a[1]-(36-9*a[3]-4*a[2]);
              if a[1]<0 then a[1]:=0;
              a[2]:=0;
            end;
          if a[2]>7-a[3]*2 then
            begin
              a[2]:=a[2]-7+a[3]*2;
              a[1]:=a[1]-(36-9*a[3]-4*(7-a[3]*2));
              if a[1]<0 then a[1]:=0;
            end;
          a[3]:=0;
        end;
      ans:=ans+a[2] div 9;
      a[2]:=a[2] mod 9;
      if a[2]>0 then
        begin
          inc(ans);
          a[1]:=a[1]-(36-a[2]*4);
        end;
      if a[1]<0 then a[1]:=0;
      ans:=ans+a[1] div 36;
      a[1]:=a[1] mod 36;
      if a[1]>0 then inc(ans);
      writeln(ans);
    end;
end.